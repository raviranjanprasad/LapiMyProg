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
   {"path",1, NULL, 'p'}
};

class DirScan{

   vector<string> dirlist;
   vector<string> fileList;
public:
   DirScan(){
     dirlist = vector<string>();
     fileList = vector<string>();
   }

   int getdir(string dir,vector<string> &dirlist, vector<string> &fileList);
   int isDir(string path);
   vector<string> getDirList() const;
   vector<string> getFileList() const;
   void DisplayDir();
   void DisplayFile();
   ~DirScan();
};

//Dir List Getter Function
vector<string>  DirScan::getDirList() const
{
     return dirlist;
}

//File List Getter Function
 vector<string>  DirScan::getFileList() const
{
    return fileList;
}

DirScan::~DirScan(){
  cout <<"Destructor Called\n";
}

int main(int argc,char *argv[])
{
    int c;
    DirScan dScan;
    vector<string> Argdirlist;
    vector<string> ArgfileList;

    while ((c = getopt_long(argc,argv,"hp:", longopts, NULL)) != -1){
     switch(c) {
                 case 'h' :
                            cout<<"Usages: \n";
                            cout<<"./DirScan -[path|p] <Dir Path]\n";
                            break;

                 case 'p' :
                           //string DirPath(optarg);
                           Argdirlist = dScan.getDirList();
                           ArgfileList = dScan.getFileList();
                           //cout << "DirPath = " << DirPath << " Argdirlist =  "<< Argdirlist <<" ArgfileList =  "<< ArgfileList << endl;
                           cout << "DirPath = " << optarg << " Argdirlist =  "  << endl;
                           break;

                 default :
                           cout<<"Usages: \n";
                           cout<<"./DirScan -[path|p] <Dir Path]\n";
                           break;

         }
  }

   return 0;
}
