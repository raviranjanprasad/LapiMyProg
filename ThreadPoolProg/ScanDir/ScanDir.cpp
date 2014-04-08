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
   DirScan(vector<string> dL="", vector<string> fL=""):
          dirlist(dL),fileList(fL){}
   int getdir(string dir,vector<string> &dirlist, vector<string> &fileList);
   int isDir(string path);
   vector<string> &getDirList() const;
   vector<string> &getFileList() const;
   void DisplayDir();
   void DisplayFile();
};

//Dir List Getter Function
vector<string> & DirScan::getDirList() const
{
     return dirlist;
}

//File List Getter Function
 vector<string> & DirScan::getFileList() const
{
    return fileList;
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

void DirScan::DisplayDir(){
    cout <<"======================\n";
    cout << "[DIR LIST]\n" ;
    cout <<"======================\n";
    for (unsigned int i = 0;i < dirlist.size();i++) {
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
    vector<string> Argdirlist;
    vector<string> ArgfileList;

  while ((c = getopt_long(argc,argv,"hp:", longopts, NULL)) != -1){
     switch(c) {
	         case 'h' :
		            printf("Usages: \n");
			    printf("./DirScan -[path|p] <Dir Path]\n");
			    break;

		 case 'p' : 
                              
		           break;
		 
		 default :
		           printf("Usages: \n");
				   printf("./DirScan -[path|p] <Dir Path]\n");
				   
					
	 }
  }
    string dir = string(argv[1]);
    vector<string> dirlist = vector<string>();
    vector<string> fileList = vector<string>();

    getdir(dir,dirlist,fileList);
    return 0;
}

=============================

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

==============================

class threaded_class
{
public:
    threaded_class()
        : m_stoprequested(false), m_running(false)
    {
        pthread_mutex_init(&m_mutex);
    }
 
    ~threaded_class()
    {
        pthread_mutex_destroy(&m_mutex);
    }
 
    // Create the thread and start work
    // Note 1
    void go() 
    {
        assert(m_running == false);
        m_running = true;
        pthread_create(&m_thread, 0, &threaded_class::start_thread, this);
    }
 
    void stop() // Note 2
    {
        assert(m_running == true);
        m_running = false;
        m_stoprequested = true;
        pthread_join(&m_thread, 0);
    }
 
    int get_fibonacci_value(int which)
    {
        pthread_mutex_lock(&m_mutex); // Note 3 
        int value = m_fibonacci_values.get(which); // Note 4 
        pthread_mutex_unlock(&m_mutex);
        return value;
    }
 
private:
    volatile bool m_stoprequested; // Note 5
    volatile bool m_running;
    pthread_mutex_t m_mutex; // Variable declarations added 4/14/2010
    pthread_t m_thread;
 
    std::vector<int> m_fibonacci_values;
 
    // This is the static class function that serves as a C style function pointer
    // for the pthread_create call
    static void start_thread(void *obj)
    {
        //All we do here is call the do_work() function
        reinterpret_cast<threaded_class *>(obj)->do_work();
    }
 
    int fibonacci_number(int num)
    {
        switch(num)
        {
            case 0:
            case 1:
                return 1;
            default:
                return fibonacci_number(num-2) + fibonacci_number(num-1); // Correct 4/6/2010 based on comments
        };
    }    
 
    // Compute and save fibonacci numbers as fast as possible
    void do_work()
    {
        int iteration = 0;
        while (!m_stoprequested)
        {
            int value = fibonacci_number(iteration);
            pthread_mutex_lock(&m_mutex);
            m_fibonacci_values.push_back(value);
            pthread_mutex_unlock(&m_mutex); // Note 6
        }
    }                    
};

==================================================================

class threaded_class
{
public:
    threaded_class()
        : m_stoprequested(false), m_running(false)
    {
        pthread_mutex_init(&m_mutex);
    }
 
    ~threaded_class()
    {
        pthread_mutex_destroy(&m_mutex);
    }
 
    // Create the thread and start work
    // Note 1
    virtual void launch() 
    {
        assert(m_running == false);
        m_running = true;
        pthread_create(&m_thread, 0, &threaded_class::start_thread, this);
    }
 
    virtual void stop() // Note 2
    {
        assert(m_running == true);
        m_running = false;
        m_stoprequested = true;
        pthread_join(&m_thread, 0);
    }
 
    
 
private:
    volatile bool m_stoprequested; // Note 5
    volatile bool m_running;
    pthread_mutex_t m_mutex; // Variable declarations added 4/14/2010
    pthread_t m_thread;
 
    std::vector<int> m_fibonacci_values;
 
    // This is the static class function that serves as a C style function pointer
    // for the pthread_create call
    static void start_thread(void *obj)
    {
        //All we do here is call the do_work() function
        reinterpret_cast<threaded_class *>(obj)->do_work();
    }
 
    
 
    // Compute and save fibonacci numbers as fast as possible
    void do_work()
    {
        int iteration = 0;
        while (!m_stoprequested)
        {
            
            pthread_mutex_lock(&m_mutex);
            //m_fibonacci_values.push_back(value);
            pthread_mutex_unlock(&m_mutex); // Note 6
        }
    }                    
};


http://www.postget.net/dl-files/72a86ce35cd395b3cb1f6e1a0fc33ff8/226702/3418854149/20110119/f/80/18719/professional-c-programmer-to-programmer.9780764574849.18719.pdf

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



