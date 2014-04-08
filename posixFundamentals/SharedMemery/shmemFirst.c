#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ     27
void server()
{
 char c;
 int shmid;
 key_t key;
 char *shm, *s;
 /*
  * We'll name our shared memory segment
  * "5678".
  */
 key = 5678;
 /*
  * Create the segment.
  */
 if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
  perror("shmget");
  exit(1);
 }
 printf("%d: shared memory created\n", getpid());
 /*
  * Now we attach the segment to our data space.
  */
 if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
  perror("shmat");
  exit(1);
 }
 printf("%d: shared memory attached\n", getpid());
 /*
  * Now put some things into the memory for the
  * other process to read.
  */
 s = shm;
 for (c = 'a'; c <= 'z'; c++)
  *s++ = c;
 *s = NULL;
 /*
  * Finally, we wait until the other process
  * changes the first character of our memory
  * to '*', indicating that it has read what
  * we put there.
  */
 while (*shm != '*')
  sleep(1);
 exit(0);
}

void client()
{
    int shmid;
    key_t key;
    char *shm, *s;
    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;
    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    printf("%d: shared memory received\n", getpid());
    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    printf("%d: shared memory attached\n", getpid());
    /*
     * Now read what the server put in the memory.
     */
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');
    /*
     * Finally, change the first character of the
     * segment to '*', indicating we have read
     * the segment.
     */
    *shm = '*';
    exit(0);
}
int main(void) {
 if(fork() ==0)
 {
  sleep(2);
  client();
 }
 else
 {
  server();
 }
 while(1)
  sleep(100);
 return 0;
}


