#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

void spawn(char *program, char *arg_list[])
{
   int retval;
   
   switch(fork()){

      case 0:
            execvp(program,arg_list);
            fprintf(stderr,"execvp failed\n");
            abort();
     default:
            wait(&retval);
            fprintf(stderr,"EXIT status %d\n", WEXITSTATUS(retval));
            exit(0);
   }
}

int main(int argc, char *argv[])
{
   //char *arglist[]={"ls","-l","/",NULL};
   char *arglist[]={"/home/ravi/MyProg/mainpi","25",NULL};
   spawn("/home/ravi/MyProg/mainpi",arglist);
   //spawn("ls",arglist);
   return 0;
}
