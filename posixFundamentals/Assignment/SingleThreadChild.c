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
pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;


typedef struct MyPipe{
   int a[2];
}MyPipe;

typedef struct MyData{
  int n1,n2;
}MyData;


MyPipe  fd[10];


MyData dat[10];
int workCount = 0;

void *MyThredFun(void *H)
{

   int wdata;
   int *Handle = (int*)H;
   int i, j, ret;
   int result = 0;
   printf("Thread Function Called\n");
   ret = pthread_mutex_lock( &cond_mutex );
   if (ret == 0) {

     printf( "Parent: Starting Wriing Data (%d)\n", workCount );
     workCount++;
     pthread_cond_broadcast( &condition );
     for ( j = 0 ; j < 10; j++)
     {
      dat[j].n1 = j;
      dat[j].n2 = j + 10;
      wdata = write(*Handle,dat,sizeof(dat));
     }
     printf("Writing data %d\n", wdata);     
     pthread_mutex_unlock( &cond_mutex );
     close(*Handle);
   }
   else 
   {
     assert(0);
   }
   
   
   printf("Parent finished\n");
   free(H);
   pthread_exit( NULL );
}

void *ChildThreadFun(void *H)
{
   int *Handle = (int*)H;
   int i, j, ret;
   

   pthread_detach( pthread_self() );
   printf( "Child %x: Started\n", pthread_self() );
   
       for(i=0;i < 10; i++)
       {
          while (read(*Handle,dat,sizeof(dat)) > 0)
          {
            dat[i].n1 += dat[i].n1;
            dat[i].n2 += dat[i].n2;
             
            printf("In Child Element n1: %d, n2: %d\n", dat[i].n1, dat[i].n2);
          }
       }


    
   printf( "Child %x: Finished\n", pthread_self() );
   free(H);

  
}


void Child()
{  
    
    int i, j, ret,*rdFD;
    pthread_t childID;

    printf("Child Started Reading the data....\n");
    for(i=0; i< 10; i++)
    {
       close(fd[i].a[1]);
    }
    
   for ( i = 0 ; i< 10; i++)
   {
       rdFD = (int*)malloc(sizeof(int));
       *rdFD = fd[i].a[0];
       ret = pthread_create(&childID, NULL, ChildThreadFun, rdFD );
       if (ret != 0) {
       printf( "Error creating thread %d\n", (int)childID );
      }

    }
    

}

void Parent()
{


   int i, j, ret,*wrFD;
   pthread_t threadIds[MAX];
   
   printf("Parent started\n");
   for(i = 0; i< 10; i++)
   {
     close(fd[i].a[0]);
   }

   
   for ( i = 0 ; i< MAX; i++)
   {
      wrFD = (int*)malloc(sizeof(int));
      *wrFD = fd[i].a[1];
      ret = pthread_create(  &threadIds[i], NULL, MyThredFun, wrFD );
      if (ret != 0) {
       printf( "Error creating thread %d\n", (int)threadIds[i] );
      }
   }

   

   for (i = 0 ; i < MAX; i++)
   {
      ret = pthread_join( threadIds[i], NULL );
       if (ret != 0) {
       printf( "Error joining thread %d\n", (int)threadIds[i] );
      }

   }

  while ((workCount > 0));

  for ( i = 0 ; i < MAX ; i++)
  {
    pthread_cancel( threadIds[i] );
  }
     
  pthread_mutex_destroy( &cond_mutex );
  pthread_cond_destroy( &condition );
   
}

int main(void)
{

  pid_t  Pid;
  int i;
  memset(&fd,0,sizeof(fd));
  
  for(i=0;i<10;i++){
  pipe(fd[i].a);                             /* Create two file descriptors  */
  }

  Pid = fork();

  if ( Pid == 0)                        /* Child                        */
  {
    Child();
    puts("Forked Child Called\n");
  }
  else                                  /* Parent.                      */
  {
    Parent();
    puts("Parent end");
  }
  while(1){sleep(1);}  
  return 0;
}

