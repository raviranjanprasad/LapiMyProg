#include "common.h"

int main()
{
   int data_write,data_read;
   int fd[2];
   pid_t pid;
   const char* data="Hello This is to test Pipe\n";

   char buff[BUFSIZE];
   memset(buff,'\0',sizeof(buff));
   assert(pipe(fd) == 0);

   pid=fork();
   switch(pid){

   case -1:
            perror("fork failed\n");
            exit(EXIT_FAILURE);
   case 0:
   	    data_read = read(fd[0],buff,BUFSIZE);
   	    printf("%d bytes read from pipe\n",data_read); 
            printf("Message\n");
            puts(buff);
            break;
   
   default:
   	    data_write = write(fd[1],data,strlen(data));
   	    printf("%d bytes written on pipe\n",data_write);
  }
  exit(EXIT_SUCCESS);  
}
