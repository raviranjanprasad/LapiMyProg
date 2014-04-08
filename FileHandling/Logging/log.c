#include"common.h"
#include"log.h"

int ErrLogCreated = 0;

void ErrLog(char *msg){

    FILE *fp;

    if(!ErrLogCreated){
       fp = fopen(LOGFILE,"w+");
       assert(fp != NULL);
       ErrLogCreated = 1;
    }
    else{
      fp = fopen(LOGFILE,"a");
      assert(fp != NULL);
    }
    
    fputs(msg,fp);
    fclose(fp);
}
