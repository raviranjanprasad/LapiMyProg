#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<dirent.h>
#include<errno.h>

int main()
{
   int fds[5]= {0, 0,0,0,0};

   char buf[1024];
   int i,j,f1i,child;

   
   pipe(fds);
   f1 = open("SharedFile.txt" , O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);

   for(i=0;i<5;i++){
    
      child = fork();
      if(child > 0)
      {
          continue
      }
      else
      {
           int pid = getpid();
           write(f1,&pid,sizeof(pid));
           write(fds[i],"Child Signals",strlen("Child Signals"));
      }
   }

   printf ("In Parent\n");
   
}
