/*When Parent writes and child reads from pipe we don't get complete data,if the size of file is bigger than BUFSIZE
  while writing on pipe done by child and read by parent make wohle data write and read on pipe*/
#include "common.h"

int main(int argc,char *argv[])
{
   int data_write,data_read;
   int fd[2];
   int inFile,readFile;
   pid_t pid;

   assert(argc == 2);
   inFile=open(argv[1],rflag);
   assert(inFile != -1);

   

   char buff[BUFSIZE];
   memset(buff,'\0',sizeof(buff));
   assert(pipe(fd) == 0);

   pid=fork();
   switch(pid){

   case -1:
            perror("fork failed\n");
            exit(EXIT_FAILURE);
   case 0:
   	    /*data_read = read(fd[0],buff,BUFSIZE);
   	    printf("%d bytes read from pipe\n",data_read); 
            printf("Message\n");
            puts(buff);
            break;*/
            while((readFile = read(inFile,buff,BUFSIZE)) > 0){
   	         data_write = write(fd[1],buff,readFile);
   	         printf("%d bytes written on pipe\n",data_write);
            }
            close(inFile);
            //break;
   
   default:
            //wait(0);
   	    data_read = read(fd[0],buff,BUFSIZE);
   	    printf("%d bytes read from pipe\n",data_read); 
            printf("Message\n");
            puts(buff);
            /*while((readFile = read(inFile,buff,BUFSIZE)) > 0){
   	         data_write = write(fd[1],buff,readFile);
   	         printf("%d bytes written on pipe\n",data_write);
            }*/
            
  }
  exit(EXIT_SUCCESS);  
}
