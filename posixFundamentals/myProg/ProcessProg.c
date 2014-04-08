#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int i=0;
  int j=0;
  int fds[2]= {0, 0};
  char buf[40];
  pipe(fds);
  int rdFd = fds[0];
  int wrFd = fds[1];
  //printf ("In Parent\n");
  //printf("pid = %d; ppid = %d addr of i = ox%x\n", getpid(), getppid(), &i);
  pid_t flag = fork();
  switch(flag){

     case 0: 
             printf ("In Child\n");
             write(wrFd,"Child Signals",strlen("Child Signals"));
             close(wrFd);
             break;
     default:
             printf ("In Parent\n");
             read(rdFd,buf,sizeof(buf));
             printf("%s\n", buf); 
             close(rdFd);
  }
  /*while(j == 0) {
             printf ("In Parent\n");
             read(rdFd,buf,sizeof(buf));
             printf("%s\n", buf); 
             j++;
   }*/
  
  //printf("In Child\n");
  //printf("pid = %d; ppid = %d\n addr of i = ox%x\n", getpid(), getppid(), &i);
  return 0;
}