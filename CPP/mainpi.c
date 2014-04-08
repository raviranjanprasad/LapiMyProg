#include<stdio.h>

int main(int argc, char *argv[])
{
   int j = atoi(argv[1]);
   j = j - 5;
   printf("The value of Argument passsed is now %d\n",j);
   return 0;
}
