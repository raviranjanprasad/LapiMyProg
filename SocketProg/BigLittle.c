#include<stdio.h>
#include<sys/types.h>

#define BIG 0
#define LITTLE 1

int checkByteOrder()
{
   short int num = 0x0001;
   char *ch = (char*)&num;
   return *ch ? LITTLE:BIG;
}

int main()
{
   int test = checkByteOrder();
   printf("%s  ",CPU_VENDOR_OS);
   if(test)
     printf("LITTLE Endian\n");
   else
     printf("BIG Endian\n");
   return 0;
}

