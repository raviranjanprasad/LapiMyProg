
                     /* PROGRAM TO GET THE PERFECT SQUARE INTEGER*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
  int num1,i,ares,num2;
  float res=0.0,rem=0.0 ;
  clrscr();
  printf("\n Enter a number::");
  scanf("%d",&num1);
  if(num1<=0)
  {
  printf("\n Your choice is wrong::");
  getch();
  return;
  }
  num2=pow(num1,2);
  for(i=num1+1;i<num2;i++)
   {
      res=sqrt(i);
      ares=(int)res;
      rem=res-ares;
      if(rem==0.0000)
      {
       printf("The perfect square greater than %d is %d",num1,i);
       break;
       }
     }
    getch();
    }