#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<wait.h>

static int alarm_fired = 0;

void ding(int sig)
{
   alarm_fired = 1;
}

int main()
{
  pid_t pid;

  printf("Alarm application starts\n");

  pid=fork();

  switch(pid)
  {
    case -1:

            perror("fork faild\n");
            exit(1);
    case 0:
            sleep(5);
            kill(getppid(),SIGALRM);
            exit(0);

    default:
 
            printf("parent process\n");
            pause();
            signal(SIGALRM,ding);
            if(alarm_fired)
              printf("Alram fired\n");

  }
  return 0;
}
