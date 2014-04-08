#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>

void sigHld(int sig)
{
   printf("In Signal Handler 0x%x; is active now\n",pthread_self());
}

void *threadFun(void *arg)
{
  
  signal(SIGINT, sigHld);
  while(1)
  {
   int ret= sleep(10);
   if(ret != 0){
      printf("0x%x; Sleep interrrupted %d:\n", pthread_self(), ret);
   }  
  }
}
int main(int argc, char *argv[])
{
  int i,ret;
  pthread_t pt[20];
  //signal(SIGINT, sigHld);
  printf("0x%x is active Now\n",pthread_self());
  for( i=0;i < 20; i++)
  {
     ret = pthread_create(&pt[i], NULL,threadFun, NULL);
     assert(ret == 0);
     
  }
  while(1)
   sleep(2);

  return 0;
}

