/*
 * =====================================================================================
 *
 *       Filename:  process2.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  08/21/2013 03:15:35 PM
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
  int i=0;
  key_t shm_key;
  const int shared_segment_size = 0x6400;
  /* Allocate a shared memory segment. */
  segment_id = shmget (shm_key, shared_segment_size,
              S_IRUSR | S_IWUSR);
  /* Attach the shared memory segment. */
  shared_memory[3] = (char*) shmat (segment_id, 0, 0);
  printf ("shared memory22 attached at address %p\n", shared_memory);
   printf ("name=%s\n", shared_memory[i]);
   printf ("%s\n", shared_memory[i+1]);
   printf ("%s\n", shared_memory[i+2]);
  /* Detach the shared memory segment. */
  shmdt (shared_memory);
   return 0;
}
