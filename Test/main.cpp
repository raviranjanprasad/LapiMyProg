#include<stdio.h>
#include"mymath.h"

int main(int argc, char *argv[])
{
     int a, b.res;
     a=10, b=5;
     res = sum(a,b);
     printf(" sum = %d\n",res);
     res = sub(a,b);
     printf(" sub= %d\n",res);
     res = mul(a,b);
     printf(" mul= %d\n",res);
     res = div(a,b);
     printf(" div= %d\n",res);
     retrun 0;
}
