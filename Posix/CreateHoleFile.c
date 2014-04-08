#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>

#define oflag O_CREAT|O_RDWR|O_TRUNC
#define mode 0666

int main(int argc,char *argv[])
{
     char buf1[]="asdf;lkjgh";
     char buf2[]="ASDF;LKJGH";
     int fd;

     if((fd=open("WithHole.txt", oflag, mode)) == -1)
       perror("open() call failed\n");

     if(write(fd,buf1,sizeof(buf1) -1) == -1)
      perror("write() call failed\n");

     if(lseek(fd,16384,SEEK_SET) == -1)
      perror("lseek() call failed\n");

     if(write(fd,buf2,sizeof(buf2) -1) == -1)
      perror("write() after lseek failed\n");

     close(fd);
return 0;
}

