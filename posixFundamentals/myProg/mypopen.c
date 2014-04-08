#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
  int i;
  FILE *f1 = popen("ls -ltR //", "r");
  char buf[4096];
  scanf("%d",&i);
  int retFrd = fread(buf,sizeof(buf),1,f1);
  printf("retFrd = %d errono = %d  buf = %s\n", retFrd,errno,buf);
  fclose(f1);
  return 0;
}
