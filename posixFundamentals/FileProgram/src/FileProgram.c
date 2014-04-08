/*
 ============================================================================
 Name        : FileProgram.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<string.h>
#include<assert.h>

int main(int argc, char *argv[]) {
	char buf[512],buf2[512];
	int f1=open(argv[1],O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
	assert(f1);
	memset(buf,'a',sizeof(buf));

	int retWr= write(f1,buf,sizeof(buf));

	if(retWr != sizeof(buf))
	{
		//error
	}
	close(f1);

	f1 =open(argv[1],O_RDONLY,S_IRUSR|S_IWUSR);

	assert(f1);

	int retRd = read(f1,buf2, sizeof(buf2));
	if(retRd != sizeof(buf))
	{
			//error
	}

	retWr = write(f1,"1234",sizeof("1234"));
	perror("Write Failed\n");
	close(f1);

	return EXIT_SUCCESS;
}
