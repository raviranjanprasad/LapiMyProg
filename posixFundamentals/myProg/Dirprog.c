#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include<dirent.h>
#include<errno.h>


int main(int argc, char *argv[]){
 DIR *dirp = opendir(".");

while (dirp) {
    struct dirent *dp = NULL;
    errno = 0;
    if ((dp = readdir(dirp)) != NULL) {
        printf("%s\n",dp->d_name);
        if (strcmp(dp->d_name, "Dirprog") == 0) {
            closedir(dirp);
            return 0;
        }
    } else {
        if (errno == 0) {
            closedir(dirp);
            return 1;
        }
        closedir(dirp);
        return 0;
    }
 }
}
