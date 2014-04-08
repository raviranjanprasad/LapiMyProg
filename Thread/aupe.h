#ifndef _AUPE_H
#define _AUPE_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<sys/wait.h>
#include <pthread.h>
#include<string.h>

#define oflag O_CREAT|O_RDWR|O_APPEND
#define mode 0666
/* Simple function to check the return code and exit the program
 *  * if the function call failed
 *   */
static void checkResults(char *string, int rc) {
  if (rc) {
    printf("Error on : %s, rc=%d",
           string, rc);
    exit(EXIT_FAILURE);
}

#endif
