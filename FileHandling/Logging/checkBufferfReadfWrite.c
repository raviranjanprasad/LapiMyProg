#include "common.h"
#include "log.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[]){
   FILE *inFd,*outFd;
   char buf[BUF_SIZE];
   int nread;

   if(argc != 3){
     ErrLog("Insufficient arguments\n");
     assert(argc == 3);
   }

   inFd = fopen(argv[1],"r");
   if(inFd == NULL){
   ErrLog("Can't open file for Read\n");
   assert(inFd != NULL);
   }

   outFd = fopen(argv[2],"w");
   if(outFd == NULL){
   ErrLog("Can't open file for Write\n");
   assert(outFd != NULL);
   }


   while((nread=fread(buf,1,BUF_SIZE,inFd)) > 0){
     sleep(5);
     if(fwrite(buf,1,nread,outFd) != nread){
       ErrLog("Can't Write all Read bytes\n");
     }
  }

  fclose(inFd);
  fclose(outFd);

  return 0;
}
