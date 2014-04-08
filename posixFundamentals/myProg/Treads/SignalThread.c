#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

void *MyThredFun(void *H)
{
  
   int *Handle = (int*)H;
   printf("Thread Function Called\n");
   char Buff[]="Martin 1 abcdefghijklmnop ";

  write(*Handle, Buff, strlen(Buff));

  Buff[7] = '2';
  write(*Handle, Buff, strlen(Buff)+1);

  Buff[7] = '3';
  write(*Handle, Buff, strlen(Buff)+1);

  Buff[7] = '4';
  write(*Handle, Buff, strlen(Buff)+1);  
  
  close(*Handle);
  // sleep(30);
   return;
}


int main()
{
  int fds[2] = {0,0};
  int i,j,ret;
  pthread_t pid;
  char Buff[50];
  void *ret1;

  pipe(fds);
  int  wrFD = fds[1];
  int rdFD = fds[0];
  
ret = pthread_create(&pid, NULL, MyThredFun, &wrFD);
  
  if(ret != 0)
  {
    perror("Thread Creation Error\n");
    exit(1);
  }
  
  
  printf("parent Thread \n");
  //sleep(5);
  while (read(rdFD,Buff, 27) > 0)
  {
    printf("%s\n", Buff);
  }

  pthread_join(pid, &ret1);
   
  
}

