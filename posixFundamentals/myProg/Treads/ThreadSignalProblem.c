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
#include<signal.h>

pthread_rwlock_t rwl;

static void hdl (int sig, siginfo_t *siginfo, void *context)
{
        void *ret;
        printf ("In Process: %d  Sending PID: %ld, UID: %ld\n",
                      getpid(), (long)siginfo->si_pid, (long)siginfo->si_uid);
        waitpid(siginfo->si_pid, &ret, WNOHANG);
}


void *crThFun(void *arg)
{
   int i;
   struct sigaction act;
   memset (&act, '\0', sizeof(act));

   /* Use the sa_sigaction field because the handles has two additional parameters */
   act.sa_sigaction = &hdl;

   /* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
   act.sa_flags = SA_SIGINFO;

   pthread_rwlock_init(&rwl, NULL);
   pthread_rwlock_wrlock(&rwl);
   for(i=0;i<10;i++)
   {
         pthread_t pt;
         int ret = pthread_create(&pt, NULL, MyFun, NULL);
         if(ret != 0){
         perror("Thread Cretion Errror in Create Thread Fun\n");
         exit(1);
       }
       
       printf("Child thread 0x%x is waiting ...\n", pthread_self()); 
   }
}

int main()
{
   pthread_t crTh;
   int ret = pthread_create(&ctTh, NULL, crThFun, NULL);
   if(ret != 0){
         perror("Thread Cretion Errror\n");
         exit(1);
       }
   
}
