
=================================

mythread.h

class Thread
{
   public:
      Thread();
      int Start(void * arg);
   protected:
      int Run(void * arg);
      static void * EntryPoint(void*);
      virtual void Setup();
      virtual void Execute(void*);
      void * Arg() const {return Arg_;}
      void Arg(void* a){Arg_ = a;}
   private:
      THREADID ThreadId_;
      void * Arg_;

};

Thread::Thread() {}

int Thread::Start(void * arg)
{
   Arg(arg); // store user data
   int code = thread_create(Thread::EntryPoint, this, & ThreadId_);
   return code;
}

int Thread::Run(void * arg)
{
   Setup();
   Execute( arg );
}

/*static */
void * Thread::EntryPoint(void * pthis)
{
   Thread * pt = (Thread*)pthis;
   pthis->Run( Arg() );
}

virtual void Thread::Setup()
{
        // Do any setup here
}

virtual void Thread::Execute(void* arg)
{
        // Your code goes here
}


==========================
#include "mythread.h"
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
                            printf("./DirScan -[path|p] <Dir Path]\n");
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
                           printf("./DirScan -[path|p] <Dir Path]\n");


         }
  }
return 0;
}

==========================
"./mercury/mss/immsgverify-common.cxx"
//+---------------------------------------------------------------------------
//
// Function:    ImMsgVerify::scanMFS
//
// Synopsis:    Step 1, scan the blob file names under buckets listed in buckets.dir.
//              Generate mfs_scan.X file for each bucket.
//              It uses multiple threads, each of which scan one bucket dir.
//----------------------------------------------------------------------------

void ImMsgVerify::scanMFS()
{
    getBucketDirs(strl_bucketDir);
    setBucketListToKeep(strl_bucketDir);

    //change to the root of MFS
    if (chdir(msgFileDir) == -1) {
        fprintf(stderr, "Failed to execute 'chdir %s'", msgFileDir);
        exit(1);
    }

    int ThreadsToRun = threadCount;

    ARRAYOF(ThreadJoinId) allThreads;
    ARRAYOF(ScanThreadP) scanThreads;

    for (int i = 0 ; i < ThreadsToRun ; i++ )
    {
        scanThreads[i] = new ScanThread(this) ;
        ThreadJoinId tid;
        scanThreads[i]->launch(&tid);
        allThreads.add(tid);
    }

    // Wait for spawned threads to all finish.
    for (ARRAYITER(ThreadJoinId) fri(allThreads); fri.more(); )
        Thread::join(fri());

    if (isQuitting())
        exit(1);
}

bash-2.03$ vim ./mercury/mss/immsgverify-common.hxx
//+---------------------------------------------------------------------------
//
// Class:       ScanThread
//
// Synopsis:    This class encapsulates a thread that scan a bucket directory in MFS
//
//----------------------------------------------------------------------------
class ScanThread : public OmuThread
{
public:
    ScanThread(ImMsgVerify * app)
        :OmuThread("ScanThread"), _myApp(app)
    {
        setJoinable(TRUE);
    }
    virtual ~ScanThread() {};

    virtual void threadmain();

private:
    ImMsgVerify * _myApp;
    boolean isAbsPath(SString const & path);
    boolean isAltPath(SString const & path);
    void scanDirRecursive(SString const & dir, int fd, SString const & altPath);  // fd: the file to write into
};

//+---------------------------------------------------------------------------
//
// Function:    ScanThread::scanDirRecursive
//
// Synopsis:    Dumps out all of blob file names under a bucket recursively
//              Need do it super-fast. Do not 'stat' the entry if it matches
//              our blob file pattern. Otherwise 'stat' the entry.
//----------------------------------------------------------------------------

void ScanThread::scanDirRecursive(SString const & bucketDir,
                                  int fd,
                                  SString const & str_altPath)
{
    SString bucketPath;          // full path of bucketDir to traverse
    SString bucketOutputPath;    // output prefix of bucket path

    // get normalized form of messageFilesDir
    SString msgFileDir = _myApp->getMsgFileDir();
    if (msgFileDir[-1] == '/') {
        msgFileDir.Truncate(Length(msgFileDir) - 1);
    }

    if( bucketDir.HasPrefix("/")) {
        // bucketDir is absolute path
        bucketPath = bucketDir;
        if (bucketDir.HasPrefix(msgFileDir)) {
            bucketOutputPath = bucketDir.Segment(Length(msgFileDir) +1,
                                                 Length(bucketDir) -1);
        } else {
            // we would not have removed the prefix when we added the
            // message file path to the database, so just use absolute
            // bucket dir path
            bucketOutputPath = bucketDir;
        }
    } else {
        // bucketDir is relative path
        bucketPath = msgFileDir + SString("/") + bucketDir;
        bucketOutputPath = bucketDir;
    }

    // open the directory for reading
    DIR* dir = opendir(bucketPath.AsPtr());
    if (!dir) {
        fprintf(stderr, "Can not open directory %s\n", bucketPath.AsPtr());
        _myApp->setQuitting();
        return;
    }

    struct stat dir_stat;       // used by stat().
    char buffer[MAX_PATH_NAME];

    // scan the directory, traversing each sub-directory, and
    // matching the pattern for each file name.
    while (struct dirent* entry = readdir(dir)) {
        // skip the entries starting with "."

        if ((entry->d_name) &&
            entry->d_name[0]== '.')
            continue;


        //check if entry name matches the pattern to avoid calling 'stat'
        if (SString(entry->d_name).HasMatch(SCANPATTERN)) {
            int size;
            // Add the alt path in the file, if exists
            if (Scalar(str_altPath) > 0) {
                if (bucketDir.HasPrefix(str_altPath)) {
                    SString str_temp = bucketDir.Segment(Length(str_altPath) +1,
                                                         Length(bucketDir) -1);
                    // We are certain that str_altPath doesn't have
                    // trailing "/" in the path.
                    if (isAbsPath("/" + str_temp))
                        size = snprintf(buffer, sizeof(buffer), "/%s/%s %s\n",
                                        str_temp.AsPtr(), entry->d_name,
                                        str_altPath.AsPtr());
                    else
                        size = snprintf(buffer, sizeof(buffer), "%s/%s %s\n",
                                        str_temp.AsPtr(), entry->d_name,
                                        str_altPath.AsPtr());
                }
            } else {
                // Dumping out relative path with message file name
                // Relative directory path leading to the message file.
                // Decrease dump file size, make comparison easier because
                // dumped message file from DB contains only relative path.
                size = snprintf(buffer, sizeof(buffer), "%s/%s\n",
                                bucketOutputPath.AsPtr(),
                                entry->d_name);
            }
            write(fd, buffer, size);
        } else {
            SString subDir = bucketDir + SString ("/") + SString (entry->d_name);
            if (stat(subDir.AsPtr(), &dir_stat) == -1) {
                fprintf(stderr, "Failed to 'stat' %s\n", subDir.AsPtr());
                _myApp->setQuitting();
                return;
            }
            // is this a directory?
            if (S_ISDIR(dir_stat.st_mode)) {
                if (_myApp->isQuitting())
                    return;
                scanDirRecursive(subDir, fd, str_altPath); // Scan this subdirectory
            }
        }
    }
    closedir(dir);
}


//+---------------------------------------------------------------------------
//
// Function:    ScanThread::threadmain
//
// Synopsis:    Gets a bucket, scans it and dump out all of blob file
//              names under it to a file
//
//----------------------------------------------------------------------------
void ScanThread::threadmain()
{
    SString str_BucketDir;
    int nBucket = -1;

    while ((nBucket = _myApp->getNextBucketDir(str_BucketDir)) != -1) {

        if (_myApp->Args.progVerbose) {
            FileSnk * fileSnk = _myApp->getCurrFileSnk();
            fprintf(*fileSnk,  "Thread %d is scanning bucket dir %s\n",
                   getId(), str_BucketDir.AsPtr());
        }

        SString str_ScanFile =  SString(_myApp->getWorkDir()) + SString("/")
            + SString (MfsScanPrefix) + SString(nBucket);


        int scanFD = open(str_ScanFile.AsPtr(), O_WRONLY | O_CREAT | O_TRUNC
                          | O_LARGEFILE, PERM_OWNER | PERM_GROUP_R);
        if (scanFD == -1) {
            fprintf(stderr, "Can not open file %s\n", str_ScanFile.AsPtr());
            _myApp->setQuitting();
            return;
        }
        SString str_altPath;
        if (_myApp->Args.includeAltTiersArg && isAltPath(str_BucketDir))
            str_altPath = str_BucketDir;
        scanDirRecursive(str_BucketDir, scanFD, str_altPath);
        snimCloseFd(scanFD);
    }
}


