                       
					/*PROGRAM FOR THE FABINOCII SERIES*/
#include<stdio.h>
#include<conio.h>
int fabnoci(int n)
 {
   static int f1=0,f2=1,temp;
     if(n<2)
     {
     f1=0;
     f2=1;
     }
     else
     {
     fabnoci(n-1);
     temp=f2;
     f2=f1+f2;
     f1=temp;
     }
    printf("%d ",f2);
 }

void main()
{
 int n;
 clrscr();
 printf("\n FABNOCII SERIES");
 printf("\n enter a number:");
 scanf("%d",&n);
 fabnoci(n);
  getch();
 }