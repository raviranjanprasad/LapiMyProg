#include<stdio.h>
#include<stdlib.h>
#include<fnctl.h>
#include<sys/types.h>

int main(void){

 char buf[1824];
 int fi = open("/tmp/m1", O_WRONLY|O_NONBLOCK);
 memset(buf,'A',sizeof(buf));

 int retRd = read(f1,buf, sizeof(buf));
 printf("retRd  = %d; buf = %s\n", readRd, buf);
 close(f1);
 return 0;
}

