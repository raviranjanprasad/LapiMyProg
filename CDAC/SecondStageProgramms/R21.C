
                       /*PROGRAM FOR number*2^pow */

#include<stdio.h>
#include<conio.h>

/*FUNCTION TO CALCULATE THE  POWER*/
void calculate(int number,int pow)
  {
   int i,mult=1,finalprod;
   for(i=1;i<=pow;i++)
    mult=2*mult;
    finalprod=number*mult;
    printf("\n The vlue of number*2^pow::\n");
    printf("\n %d*2^%d=%d",number,pow,finalprod);
    }

/* FUNCTION MAIN */
void main()
 {
  int number,pow;
  clrscr();
  printf("\n enter the number::");
  scanf("%d",&number);
  printf("\n enter the power raised to 2::");
  scanf("%d",&pow);
  calculate(number,pow);
  getch();
  }
