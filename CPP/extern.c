#include<stdio.h>
#include"myFile.h"

var=25;
int main()
{
   int var;
   var = 10;
   int x=fun();
   printf("var=%d, extern var=%d\n",var,x);
   return 0;
}

int fun()
{
   printf("I am in external Fun\n");
   return var;
}

