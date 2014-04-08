#include "aupe.h"
static int glob=0;
//pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtx;
pthread_mutexattr_t mtxAttr;

void *thrdFun(void *arg){
   int loop =*((int*) arg);
   int loc,i,mres;
   int s;

   s=pthread_mutexattr_settype(&mtxAttr,PTHREAD_MUTEX_ERRORCHECK);
   if(s!=0)
      perror("Setting Mutex Attribute as PTHREAD_MUTEX_ERRORCHECK failed\n");

   s=pthread_mutex_init(&mtx,&mtxAttr);
   if(s!=0)
      perror("Initializing Mutex Attribute failed\n");
   printf("For thread ID=%lu Arg loop=%d\n",pthread_self(),loop);

   /*mres=pthread_mutex_unlock(&mtx);
   if(mres != 0)
        perror("First Mutex unlock failed\n");

   mres=pthread_mutex_lock(&mtx);
   if(mres != 0)
        perror("First Mutex lock failed\n");*/
   mres=pthread_mutex_lock(&mtx);
   if(mres != 0)
        perror("Second Mutex lock failed\n");
   for(i=0;i<loop;i++){
     loc = glob;
     loc++;
     glob = loc;
   }
   mres=pthread_mutex_unlock(&mtx);
   if(mres != 0)
        perror("Second Mutex lock failed\n");
   s = pthread_mutexattr_destroy(&mtxAttr); /* No longer needed */
   if(s!=0)
      perror("pthred_mutexattr_destroy failed\n");
   pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t t1, t2;
  int res;
  int val=atoi(argv[1]);
  printf("loop=%d\n",val);
  res = pthread_create(&t1,NULL,thrdFun,&val);
  if(res != 0)
        perror("First Thread creation failed\n");
  res = pthread_create(&t2,NULL,thrdFun,&val);
  if(res != 0)
        perror("Second Thread creation failed\n");
  res=pthread_join(t1, NULL);
  if(res != 0)
        perror("First Thread join failed\n");
  res=pthread_join(t2, NULL);
  if(res != 0)
        perror("Second Thread join failed\n");
  printf("Glob = %d\n",glob);

  return 0;
}

