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
int run = 0;
//char *c = NULL;

void threadClenaUpRoutine(void *arg)
{
   printf("Inside Clean Method\n");
   char *c = (char*) arg;
   printf("Char c = 0x%x; %s\n",c,c);
   free(arg);   
}
void *theadMain(void *arg)
{
   //char *c = (char*)malloc(1024);
   c = (char*)malloc(1024);
   assert(c);
   int i = 0;
   while ( run == 0)
   {
       char *c ;
 
      //printf("Child thead 0x%x is running...\n", pthread_self());
      pthread_cleanup_push(threadClenaUpRoutine , c);
      c = (char*)malloc(1024);
      assert(c);
      memset(c,0x0, 1024);
      sprintf(c,"iteration no:" , i++);
      sleep(1);
      pthread_cleanup_pop(0);
   }

      printf("Child thead 0x%x is existing...\n", pthread_self());
   free(c);
   return NULL; 
}


int main() {
   pthread_t pt;
   void *ret1;

   int ret = pthread_create(&pt, NULL, theadMain, &rwl);
   if(ret != 0){
         perror("Thread Cretion Errror\n");
         exit(1);
    }

   printf("Parent to do some job here...\n");
   sleep(5);
   pthread_cancel(pt);
   printf("%s\n",c);
   //run = 1;
   printf("Parent thead 0x%x is waiting ..\n",pthread_self());
   if(pthread_kill(pt,
   pthread_join(pt, &ret1);

   printf("Child Thread have exited.....\n");
   return 0;
}
