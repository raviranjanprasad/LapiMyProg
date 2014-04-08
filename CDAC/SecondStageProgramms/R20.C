
                    /*PROGRAM TO CONVERT FEHRENHEIT TO CELSIUS*/

#include<stdio.h>
#include<conio.h>
void main()
{
 int fer,i;
 float cel;
 clrscr();
 for(fer=0;fer<=212;fer=fer+20)
  {
   printf("\n Fahrenheit       Celsius\n");
   for(i=fer;i<=fer+20;i++)
   {
      cel=5.0/9.0*(i-32);
      printf("\n%5d%20.3f\n",i,cel);
      if(i>=212)
       break;
    }
    getch();
    clrscr();
   }

   getch();
}

