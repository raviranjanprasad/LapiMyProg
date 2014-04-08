#include <sys/stat.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
int main() {
   /*
   ** Code snippet.
   */
   struct stat sb;
   utsname unameData;
   uname(&unameData);
   string release = unameData.release;
   string platform = unameData.sysname;
   string pathname="/dev/mapper";
   /*cout<< "Init: unameData.sysname: "<< unameData.sysname <<endl;
   cout<< "Init: unameData.nodename: "<< unameData.nodename <<endl;
   cout<< "Init: unameData.release: "<< unameData.release <<endl;
   cout<< "Init: unameData.version: "<< unameData.version <<endl;
   cout<< "Init: unameData.machine: "<< unameData.machine <<endl;*/

   if(platform.find("Linux")==0 && (release.find("2.6") == 0 || release.find("2.4") == 0)){
      if((stat(pathname.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode)) && (0== system("pidof -x multipathd > /dev/null"))){
          if(0==system("/sbin/multipath -F"))
          //cfitrace("INFO: Flush out the stale/faulty multipath devices");
            cout<<"INFO: Flush out the stale/faulty multipath devices"<<endl;
      }
      
   }

   return 0;
}

