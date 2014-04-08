#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int i=0;
__sighandler_t oldAction = NULL;
void sighandler_SIGINT(int sig)
{
   printf("sig = %d\n", sig);
   //oldAction(sig);
}
void sighandler_SIGFPE(int sig)
{
   printf("sig = %d\n", sig);
   i = 1;
   return;
   exit(sig);
   //oldAction(sig);
}

void mysigint()
{
    printf("I caught the SIGINT signal!\n");
    return;    
} 

/* Our own SIGKILL handler */
void mysigkill()
{
    printf("I caught the SIGKILL signal!\n");
    return;    
} 

/* Our own SIGHUP handler */
void mysighup()
{
    printf("I caught the SIGHUP signal!\n");
    return;    
} 

/* Our own SIGTERM handler */
void mysigterm()
{
    printf("I caught the SIGTERM signal!\n");
    return;    
} 

int main(void)
{
   
   //oldAction  = signal(SIGINT, sighandler_SIGINT);
   oldAction  = signal(SIGFPE, sighandler_SIGFPE);
   printf("oldAction 0x%x\n", oldAction);

   /* Use the signal() call to associate our own functions with
       the SIGINT, SIGHUP, and SIGTERM signals */
    if (signal(SIGINT, mysigint) == SIG_ERR)
       printf("Cannot handle SIGINT!\n");        
    if (signal(SIGHUP, mysighup) == SIG_ERR)
       printf("Cannot handle SIGHUP!\n");        
    if (signal(SIGTERM, mysigterm) == SIG_ERR)
       printf("Cannot handle SIGTERM!\n");        
           
    /* can SIGKILL be handled by our own function? */
    if (signal(SIGKILL, mysigkill) == SIG_ERR)
        printf("Cannot handle SIGKILL!\n");        

   while(1)
   {
     int ret = sleep(5);
     printf("ret = %d\n", ret);
     //int s = 10/0;
     int s = 10/i;
     printf("s= %d\n",s);
   }
   return 0;
}
