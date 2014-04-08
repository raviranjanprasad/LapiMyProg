#include"aupe.h"

int main(int argc,char *argv[])
{

  char buff[128];
  
  if(read(0,buff,128) == -1)
     write(1,"read() operation failed",30);

  if(write(1,buff,128) == -1)
     write(1,"read() operation failed",30);

  return 0;
}
