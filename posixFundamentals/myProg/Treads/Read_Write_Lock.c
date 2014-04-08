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

pthread_rwlock_t rwl;

void *theadMain(void *arg)
{
   pthread_rwlock_t *prwl = (pthread_rwlock_t*) arg;
   printf("Child thread 0x%x is waiting ...\n", pthread_self());
   pthread_rwlock_rdlock(prwl);
   printf("Child thread 0x%x is waiting ...\n", pthread_self());
   pthread_rwlock_unlock(prwl);
   return NULL; 
}


int main() {
   pthread_t pt[5];
   void *ret1;
   int i = 5;
   pthread_rwlock_init(&rwl,NULL);
   pthread_rwlock_wrlock(&rwl);

    while(i<=5)
    {
       int ret = pthread_create(&pt[i], NULL, theadMain, &rwl);
       if(ret != 0){
         perror("Thread Cretion Errror\n");
         exit(1);
       }
       i++;
    }

   printf("Parent to do some job here...\n");
   sleep(5);

   pthread_rwlock_unlock(&rwl);
   i = 0;
   while(i < 5)
   {
      pthread_join(pt[i], &ret1);
      i++;
   }

   printf("Child Thread have exited.....\n");
   return 0;
}
