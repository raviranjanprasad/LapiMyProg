#include"aupe.h"

int main(int argc,char *argv[])
{
   char buf[]="This is to test";
   char ch;
   int nread,nwrite;
   int fd;

   switch(fork())
   {
      case 0:
               fd=open("File1.txt",oflag,mode); 
               printf("Child Writes\n");       
               /*while(nread=read(0,&buf,sizeof(buf)) > 0){
                    nwrite=write(fd,&buf,nread);
               }*/
               //nread=read(0,buf,sizeof(buf));
               nwrite=write(fd,buf,sizeof(buf));
               if(nwrite == -1)
                 printf("Child Write() failed\n");
               close(fd);
               sleep(10);
               break;
      default:
               wait((int*)0);
               fd=open("File1.txt",oflag,mode);
               printf("Parent Reads\n");
               while(nread=read(0,&ch,sizeof(ch)) > 0){
                   nwrite=write(fd,&ch,nread);
               }
               close(fd);
               break;
   }
   return 0;
}
