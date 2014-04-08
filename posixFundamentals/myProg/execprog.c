#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<dirent.h>
#include<errno.h>

int main(int argc, char **argv)
{
   pid_t chPid = fork();
   if(chPid == 0)
   {
     execl("/bin/cat","a.txt", NULL);
   }
   else
   {
     printf("Existing\n");
   }

   return 0;
}
