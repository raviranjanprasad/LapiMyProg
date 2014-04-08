#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h> /* for stat() */
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

using namespace std;

static struct option longopts[] = {
   {"help",0, NULL, 'h'},
   {"path",1, NULL, 'p'},
   {"thread",1, NULL, 't'},
   { 0,0,0,0 }
};

class DirScan{

   vector<string> dirlist;
   vector<string> fileList;
public:
   DirScan()
   {
          dirlist = vector<string>();
	  fileList =  vector<string>();
   }
   int getdir(string dir,vector<string> &dirlist, vector<string> &fileList);
   int isDir(string path);
   vector<string> &getDirList();
   vector<string> &getFileList();
   void setDirList(vector<string> &dV);
   void setFileList(vector<string> &fV);
   void DisplayDir();
   void DisplayFile();
   ~DirScan();
};

DirScan:: ~DirScan()
{
   cout << "Destructor Calling: " <<endl;
}
//Dir List Getter Function
vector<string>  &DirScan::getDirList()
{
     return dirlist;
}

//File List Getter Function
 vector<string> &DirScan::getFileList()
{
    return fileList;
}

void DirScan::setDirList(vector<string> &dV)
{
   dirlist = dV;
}

void DirScan::setFileList(vector<string> &fV)
{
  fileList = fV;
}
/*Function to Check for Directory*/
int DirScan::isDir(string path)
{
    struct stat stat_buf;
    stat( path.c_str(), &stat_buf);
    int is_dir = S_ISDIR( stat_buf.st_mode);
    //cout <<"Dir :Path "<<path.c_str()<<endl;
    return ( is_dir ? 1: 0);
}

/*function... might want it in some class?*/
int DirScan::getdir (string dir, vector<string> &dirlist, vector<string> &fileList)
{
    DIR *dp;
    struct dirent *dirp; //*dirFp ;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp (dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0) {
            //dirlist.push_back(string(dirp->d_name));

            string Tmp = dir.c_str()+ string("/") + string(dirp->d_name);
            if(isDir(Tmp)) {
            //if(isDir(string(dir.c_str() + dirp->d_name))) {
	        //cout << "Dir :" <<Tmp << endl;
                dirlist.push_back(Tmp);
                getdir(Tmp,dirlist,fileList);
            } else {
                //cout << "Files :"<<dirp->d_name << endl;
                fileList.push_back(string(Tmp));
            }

        }
    }
    closedir(dp);
    return 0;
}

void DirScan::DisplayDir(){
    cout <<"======================\n";
    cout << "[DIR LIST]\n" ;
    cout <<"======================\n";
    for (unsigned int i = 0;i < dirlist.size();i++) 
        cout << dirlist[i] << endl;

}

void DirScan::DisplayFile(){
    cout <<"======================\n";
    cout << "[FILE LIST]\n" ;
    cout <<"======================\n";
    for (unsigned int i = 0; i < fileList.size(); i++)
        cout << fileList[i]<< endl;

}

int main(int argc,char *argv[])
{

    int c;
    DirScan dScan;
    char *getPath;
    string DirPath;
    int noOfThreads;
    vector<string> Argdirlist;
    vector<string> ArgfileList;

  while ((c = getopt_long(argc,argv,"hp:", longopts, NULL)) != -1){
     switch(c) {
	         case 'h' :
		            printf("Usages: \n");
			    printf("./DirScan --[path|p]  <Dir Path>\n");
			    printf("--[thread|t] <no of Threads> \n");
			    printf("--help\n");
			    break;
	         case 't' :
		            noOfThreads = atoi(optarg);
			    cout <<"No of Scanning Threads : " <<noOfThreads << endl;
			    break;

		 case 'p' : 
		           getPath = new char[strlen(optarg) + 1];
			   strcpy(getPath,optarg);
                           DirPath = getPath;
			   Argdirlist = dScan.getDirList();
			   ArgfileList = dScan.getFileList();
			   dScan.getdir(DirPath,Argdirlist,ArgfileList);
			   dScan.setDirList(Argdirlist);
			   dScan.setFileList(ArgfileList);
			   dScan.DisplayDir();
			   dScan.DisplayFile();
		           break;
		 
		 default :
			   printf("Usages: \n");
			   printf("./DirScan --[path|p]  <Dir Path>\n");
			   printf("--[thread|t] <no of Threads> \n");
			   printf("--help\n");
			   break;
					
	 }
  }
return 0;
}

