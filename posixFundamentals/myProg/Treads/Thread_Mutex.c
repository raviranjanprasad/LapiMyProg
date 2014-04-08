#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<dirent.h>
#include<errno.h>
#include<pthread.h>
#include<sys/wait.h>
#include<assert.h>

#define MAX 5
pthread_mutex_t cntr_mutex =  PTHREAD_MUTEX_INITIALIZER;

long var = 0L;

void *myThread(void *arg) {
  int i, ret;

  for(i=0;i< 100; i++)
  {
     ret = pthread_mutex_lock(&cntr_mutex);
     assert(ret == 0);
 
     var++;
     
     ret = pthread_mutex_unlock(&cntr_mutex);
     assert(ret == 0);    

  }

  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
   int ret, i;
   pthread_t pid[MAX];

   for(i=0; i< MAX; i++)
   {
      ret = pthread_create(&pid[i], NULL, myThread, NULL);
      assert(ret == 0);
   }

   for(i=0; i< MAX; i++)
   {
      ret = pthread_join(pid[i], NULL);
      assert(ret == 0);
   }

   printf("The final value of Var=%ld\n", var);

   ret = pthread_mutex_destroy(&cntr_mutex);
   assert( ret == 0);
   
   return 0;
}
