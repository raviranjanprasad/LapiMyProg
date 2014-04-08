/* Example of using sigaction() to setup a signal handler with 3 arguments
 * including siginfo_t.
 */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

 
static void hdl (int sig, siginfo_t *siginfo, void *context)
{
        void *ret;
	printf ("In Process: %d  Sending PID: %ld, UID: %ld\n",
		      getpid(),	(long)siginfo->si_pid, (long)siginfo->si_uid);
        waitpid(siginfo->si_pid, &ret, WNOHANG);
}
 
int main (int argc, char *argv[])
{
	struct sigaction act;
        pid_t pid;
	memset (&act, '\0', sizeof(act));
 
	/* Use the sa_sigaction field because the handles has two additional parameters */
	act.sa_sigaction = &hdl;
 
	/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	act.sa_flags = SA_SIGINFO;
 
	if (sigaction(SIGINT, &act, NULL) < 0) {
		perror ("sigaction");
		return 1;
	}
 
        if (sigaction(SIGCHLD, &act, NULL) < 0) {
                perror ("sigaction");
                return 1;
        }

        pid = fork();
        if(pid == 0)
        {
           printf("I am chid pid= %d , Parent pid = %d\n", pid,getppid());

           if (sigaction(SIGINT, &act, NULL) < 0) {
                perror ("sigaction");
                return 1;
           }
           sleep(2);
           exit(0);

        }
        else
        {
          printf("In side the paretn\n");
        } 
	while (1)
		sleep (10);
	return 0;
}
