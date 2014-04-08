#ifndef TLPI_HDR_H
#define TLPI_HDR_H /* Prevent accidental double inclusion */
#include <sys/types.h> /* Type definitions used by many programs */
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Prototypes of commonly used library functions, plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h> /* Prototypes for many system calls */
#include <errno.h> /* Declares errno and defines error constants */
#include <string.h> /* Commonly used string-handling functions */
#include <assert.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFSIZE 1024
#define wflag O_RDWR|O_CREAT|O_TRUNC
#define rflag O_RDONLY
#define wmode S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH

#endif
