#include "Common.h"
#include <iostream>
#include <string>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <sys/stat.h> /* for stat() */
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class DirScan{

  vector<string> dirlist;
  Mutex dir_mutex;
  vector<string> fileList;
  Mutex file_mutex;
public:

  inline static void* DirScanThrFunc(void *data);
  int getdir(string&);
  inline void AddDir(string&);
  inline void AddFiles(vector<string> &);
  inline int isDir(string&);
  void DisplayDirs();
  void DisplayFiles();
};

DirScan g_dScan;
ThreadPool g_tp;

void 
DirScan::AddDir(string &str)
{
  Guard g(&dir_mutex); // protecting dirlist from concurrent access.
  dirlist.push_back(str);
}

void
DirScan::AddFiles(vector<string> &files)
{
  Guard g(&file_mutex);
  fileList.insert(fileList.end(),files.begin(),files.end());
}

int
DirScan::isDir(string &path)
{
  struct stat stat_buf;
  stat( path.c_str(), &stat_buf);
  int is_dir = S_ISDIR( stat_buf.st_mode);
  return ( is_dir ? 1 : 0);
}

int 
DirScan::getdir(string &dir)
{
  DIR *dp;
  struct dirent *dirp, *dirFp ;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  string Dot(".");
  string DoubleDot("..");
  vector<string> l_files;
  while ((dirp = readdir(dp)) != NULL) {
    if (Dot.compare(dirp->d_name) != 0 && DoubleDot.compare(dirp->d_name) != 0) {

      string Tmp = dir.c_str()+ string("/") + string(dirp->d_name);
      if(isDir(Tmp)) {
        AddDir(Tmp);
       
        // Launch a new task to handle subdir. 
        ThreadPool::Task scanTask;
        scanTask.t_func = DirScan::DirScanThrFunc;
        scanTask.t_data = new string(Tmp);
        g_tp.QueueTask(scanTask);
      } else {
        l_files.push_back(Tmp); //for files logic should be different
      }
    }
  }
  closedir(dp);
  AddFiles(l_files);
  return 0;
}

void* 
DirScan::DirScanThrFunc(void *data)
{
  string *l_dir = reinterpret_cast<string*>(data);
 
  g_dScan.getdir(*l_dir);
  delete l_dir;
  return NULL;  
  
}

void 
DirScan::DisplayDirs()
{
  cout <<"======================\n";
  cout << "[DIR LIST]\n" ;
  cout <<"======================\n";
  Guard g(&dir_mutex); 
  for (unsigned int i = 0;i < dirlist.size();i++) 
    cout << dirlist[i] << endl;

}

void 
DirScan::DisplayFiles()
{
  cout <<"======================\n";
  cout << "[FILE LIST]\n" ;
  cout <<"======================\n";
  Guard g(&file_mutex);
  for (unsigned int i = 0; i < fileList.size(); i++)
    cout << fileList[i]<< endl;
}


main()
{
  ThreadPool::Task scanTask;

  scanTask.t_func = DirScan::DirScanThrFunc;
  scanTask.t_data = new string("/tmp");
  g_tp.QueueTask(scanTask);
  
  g_tp.Wait(); //main thread waits for all tasks to finish
  g_dScan.DisplayDirs();
  g_dScan.DisplayFiles();  
}
