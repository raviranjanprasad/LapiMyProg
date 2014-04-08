#include<stdio.h>
#include<stdlib.h>
#include<sys/unistd.h>
#include<iostream>

using namespace std;


int sum(int a, int b)
{
   return a + b;
}

int sub(int a, int b)
{
   return a - b;
}

int mul(int a, int b)
{
   return a * b;
}

int divi(int a, int b)
{
   return a / b;
}


int main(int argc,char *argv[]){
   int num1=atoi(argv[1]);
   int num2=atoi(argv[2]);

#ifdef CALSUM
   int res=sum(num1,num2);
   cout<<"Sum="<<res<<endl;
#endif
#ifdef CALSUB
   res=sub(num1,num2);
   cout<<"Sub="<<res<<endl;
#endif
#ifdef CALMUL
   res=mul(num1,num2);
   cout<<"Mul="<<res<<endl;
#endif
#ifdef CALDIV
   res=divi(num1,num2);
   cout<<"Div="<<res<<endl;
#endif
   return 0;
}
