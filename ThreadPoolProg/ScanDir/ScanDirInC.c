#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <sys/stat.h> /* for stat() */
#include <stdlib.h>
#include <unistd.h>


using namespace std;
int isDir(string path);

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &dirlist, vector<string> &fileList)
{
    DIR *dp;
    struct dirent *dirp, *dirFp ;
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
                dirlist.push_back(Tmp);
                getdir(Tmp,dirlist,fileList);
            } else {
  //              cout << "Files :"<<dirp->d_name << endl;
                fileList.push_back(string(Tmp));
            }

        }
    }
    closedir(dp);
    return 0;
}

int isDir(string path)
{
    struct stat stat_buf;
    stat( path.c_str(), &stat_buf);
    int is_dir = S_ISDIR( stat_buf.st_mode);
    //cout <<"Dir :Path "<<path.c_str()<<endl;
    return ( is_dir ? 1: 0);
}

int main(int argc,char *argv[])
{
    if(argc != 2 || argv[1] == NULL){
      cout<<"Usages : ./ScanDir <Directory Name>\n";
      exit(1);
    }
    string dir = string(argv[1]);
    vector<string> dirlist = vector<string>();
    vector<string> fileList = vector<string>();

    getdir(dir,dirlist,fileList);
//#if 0
    cout <<"======================\n";
    cout << "[DIR LIST]\n" ;
    cout <<"======================\n";
    for (unsigned int i = 0;i < dirlist.size();i++) {
        cout << dirlist[i] << endl;
        //string dirF = dir + "/" + dirlist[i];
        //getdir(dirF,fileList);
    }
//#endif
    cout <<"======================\n";
    cout << "[FILE LIST]\n" ;
    cout <<"======================\n";
    for (unsigned int i = 0; i < fileList.size(); i++)
        cout << fileList[i]<< endl;
    return 0;
}

