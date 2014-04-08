#include "common.h"

int main()
{
   int data_write,data_read;
   int fd[2];

   const char* data="Hello This is to test Pipe\n";

   char buff[BUFSIZE];
   memset(buff,'\0',sizeof(buff));
   assert(pipe(fd) == 0);

   data_write = write(fd[1],data,strlen(data));
   printf("%d bytes written on pipe\n",data_write);

   data_read = read(fd[0],buff,data_write);
   printf("%d bytes read from pipe\n",data_read); 
  
   printf("Message\n");
   puts(buff);
  exit(EXIT_SUCCESS);  
}
