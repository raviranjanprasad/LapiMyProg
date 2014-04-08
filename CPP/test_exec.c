#include<stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   //int i=10;
   //int i=atoi(argv[1]);
   //printf("The argument passed %d value %d\n",argc,i);
   char *cmdArg[]={"20",NULL};
   printf("The argument passed %d value %d\n",argc,atoi(argv[1]));
   //while(i > 0){
   while(atoi(argv[1]) > 0){
    //execl("/home/ravi/MyProg/mainpi","i",(char*)0);
    if(execv("/home/ravi/MyProg/mainpi",cmdArg))
      printf("Error in executing execv\n");
    //execl("/bin/ls","-l",(char*)0);
   }

   //printf("The value of i is %d\n",i);
   return 0;
}
