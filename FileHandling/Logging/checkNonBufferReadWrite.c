#include "common.h"
#include "log.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[]){
   int inFd,outFd,oflags,nread;
   char buf[BUF_SIZE];
   mode_t filePerms;

   if(argc != 3){
     ErrLog("Insufficient arguments\n");
     assert(argc == 3);
   }

   oflags = O_CREAT|O_RDWR;
   filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH; /* rw-rw-rw- */
   inFd = open(argv[1],O_RDONLY);
   if(inFd == -1){
   ErrLog("Can't open file for Read\n");
   assert(inFd != -1);
   }

   outFd = open(argv[2],oflags,filePerms);
   if(outFd == -1){
   ErrLog("Can't open file for Write\n");
   assert(outFd != -1);
   }


   while((nread=read(inFd,buf,BUF_SIZE)) > 0){
     sleep(5);
     if(write(outFd,buf,nread) != nread){
       ErrLog("Can't Write all Read bytes\n");
     }
  }

  close(inFd);
  close(outFd);

  return 0;
}
