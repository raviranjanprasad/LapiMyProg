#include"check.h"
#include<string.h>

typedef struct parm{
  int val;
  char *str;
}parm;

int main(int argc, char *argv[]){
   parm *ptr=(parm*)malloc(sizeof(parm));
   ptr->str = (char*)malloc(sizeof(char)*256);

   ptr->val = 100;
   strcpy(ptr->str,"This is to test");
   printf("The values are str-%s  val: %d\n",ptr->str,ptr->val);
   return 0;
}
