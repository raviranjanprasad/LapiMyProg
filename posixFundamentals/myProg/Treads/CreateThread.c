#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void *threadMain(void *arg)
{
   while(1){
   printf("Thread Created\n");
   sleep(1);
   }
   return;
}
int main()
{
   pthread_t pt;
   void *ret1;
   int ret = pthread_create(&pt,NULL,threadMain, NULL);
   if( ret != 0)
   {
      printf("Errot:- ret = %d\n",ret);
      return ret;
   }

   sleep(10);
//   pthread_join(pt, &ret1);
   printf("Thread Terminated\n");   
   
}
