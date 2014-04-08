#include"aupe.h"

int main(int argc,char *argv[])
{
   //char buf[]="This is to test";
   char ch[128];
   int nread,nwrite;
   int fd,cnt;

   switch(fork())
   {
      case 0:
               sleep(10);
               fd=open("File1.txt",oflag,mode); 
               printf("Child Writes\n");       
               cnt = 10;
               while(cnt--){
                  nread=read(0,ch,sizeof(ch));
                  nwrite=write(fd,ch,nread);
                  if(nwrite == -1)
                     printf("Child Write() failed\n");
               }  
               close(fd);
               sleep(10);
               /*sleep(10);
                fd=open("File1.txt",oflag,mode);
               printf("Child Writes\n");
               cnt = 10;
               while(cnt--){
                  nread=read(0,&ch,sizeof(ch));
                  nwrite=write(fd,&ch,nread);
                  if(nwrite == -1)
                     printf("Child Write() failed\n");
               }
               close(fd);*/

               break;
      default:
               fd=open("File1.txt",oflag,mode);
               printf("Parent Writes\n");
               cnt = 10;
               while(cnt--){
                  nread=read(0,ch,sizeof(ch));
                  nwrite=write(fd,ch,nread);
                  if(nwrite == -1)
                     printf("parent Write() failed\n");
               }
               close(fd);
               wait((int*)0);
               break;
   }
   return 0;
}
