#include<stdio.h>
#include<stdlib.h>


int main(void){

 char buf[1824];
 int fi = open("/tmp/m1", O_WRONLY);
 memset(buf,'A',sizeof(buf));

 int retRd = read(f1,buf, sizeof(buf));
 printf("buf = %s\n", buf);

 return 0;
}
