#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


#define MULTIPATH_FOLDER "/dev/mapper/"
#define MULTIPATH_COMMAND_PATH "/sbin/"
#define MULTIPATH_COMMAND_NAME "multipath"
#define MULTIPATH_DAEMON_PID "pidof"
#define MULTIPATH_DAEMON_NAME " -x multipathd"

#define MULTIPATH_COMMAND_OPTION_FLUSH " -f "
#define MULTIPATH_COMMAND_OPTION_FLUSHALL " -F "

using namespace std;
int main() {
   /*
   ** Code snippet.
   */
   struct stat sb;
   utsname unameData;
   //char cmd[256];
   string cmd;
   char command[1024];
   char output[1024];
   int pid;
   FILE  *stream;
   uname(&unameData);
   string release = unameData.release;
   string platform = unameData.sysname;
   string pathname="/dev/mapper";
   

   /*cout<< "Init: unameData.sysname: "<< unameData.sysname <<endl;
   cout<< "Init: unameData.nodename: "<< unameData.nodename <<endl;
   cout<< "Init: unameData.release: "<< unameData.release <<endl;
   cout<< "Init: unameData.version: "<< unameData.version <<endl;
   cout<< "Init: unameData.machine: "<< unameData.machine <<endl;*/
   memset(output,0,sizeof(output));
   strcpy(command,"pidof -x multipathd");
   stream = popen(command, "r");
   if (stream == NULL) {
         cout<<"Failded to open popen pidof -x multipathd \n";
   }
   while( fgets(output,sizeof(output),stream)){
                    printf("Output of pidof -x multipathd command :%s\n",output);
   }
   pid=atoi(output);
   cout<<"pid ="<<pid<<endl;

   if(platform.find("Linux")==0 && (release.find("2.6") == 0 || release.find("3.1") == 0)){
      if((stat(pathname.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode)) && pid){

              memset(output,0,sizeof(output));
              cout<<"Inside the if cond :" <<endl;
              cmd  = MULTIPATH_COMMAND_PATH;
              cmd += MULTIPATH_COMMAND_NAME;
              cmd += MULTIPATH_COMMAND_OPTION_FLUSHALL;

	      //strcpy(cmd.c_str(),"/sbin/multipath -F");
	      stream = popen(cmd.c_str(), "r");
              printf("Calling command %s\n",cmd.c_str());
	      if (stream == NULL) {
		      cout<<"Failded to open popen\n";
	      }
              while( fgets(output,sizeof(output),stream)){
                    printf("Output of multipath -F command :%s\n",output);
              }
              //cout<<"Output of multipath -F command :" << line<<endl;

              cout<<"INFO: Flush out the stale/faulty multipath devices"<<endl;
      }
      
   }

   return 0;
}

