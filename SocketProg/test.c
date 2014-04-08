#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showArg(char *str){
   /*char *temp=NULL;
   strcpy(temp,str);
   printf("The String %s\n",str);*/

   //char *temp = (char*)malloc(sizeof(char) * strlen(str));   
   printf("The String %s Length: %d \n",str,strlen(str));
   //printf("Length: %d \n",strlen(str));
}

int main(int argc,char *argv[]){

  showArg(argv[1]);
  return 0;
}
