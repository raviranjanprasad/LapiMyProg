/*
 * =====================================================================================
 *
 *       Filename:  process1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/2013 03:14:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (), 
 *   Organization:  Symantec
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main ()
{
  int segment_id;
  char* shared_memory[3];
  int segment_size;
  key_t shm_key;
  int i=0;
  const int shared_segment_size = 0x6400;
  /* Allocate a shared memory segment. */
  segment_id = shmget (shm_key, shared_segment_size,
            IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  /* Attach the shared memory segment. */
  shared_memory[3] = (char*) shmat (segment_id, 0, 0);
  printf ("shared memory attached at address %p\n", shared_memory);
  /* Write a string to the shared memory segment. */
   sprintf(shared_memory[i], "maddy \n");
   sprintf(shared_memory[i+1], "73453916\n");
   sprintf(shared_memory[i+2], "america\n");

  /*calling the other process*/
  system("./process2");

  /* Detach the shared memory segment. */
  shmdt (shared_memory);
  /* Deallocate the shared memory segment.*/
  shmctl (segment_id, IPC_RMID, 0);

  return 0;
}

