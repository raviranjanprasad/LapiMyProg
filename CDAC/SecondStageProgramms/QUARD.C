	       /*PROGRAM FOR THE QUARDATIC EQUATION*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
/* MAIN FUNCTION */
void main()
 {
 float a=0,b=0,c=0,d=0.0,x=0.0,x1=0,x2=0;
 clrscr();
 printf("\n Enter the cofficient of the quardatic equation::");
 scanf("%f%f%f",&a,&b,&c);

 /*CHECK WHETHER THE EQUATION  IS QUARDATIC OR LINEAR*/
 if(a==0)
  {
  printf(" Linear equation::");
  x=-(float)c/b;
  printf("Root is::%5.2f",x);
  getch();
   return;
   }

 /*CALCULATE THE DISCRIMINANT*/
    d=b*b-4*a*c;

  /* DIFFERENT CASES OF DISCRIMINANT FIRST D=0*/
 if(d==0)
  {
  printf("\n roots are real and equal::");
  x2=x1=-b/(2.0*a);
  printf("\nroots are x1=%5.2f x2=%5.2f",x1,x2);
  }

/* WHEN D>0   */
  else if(d>0)
   {
    d=sqrt(d);
    printf("\n roots are real and uneual::");
     x1=-b/2.0*a+d/2.0*a;
     x2=-b/2.0*a-d/2.0*a;
     printf("\n The roots are x1=%5.2f,x2=%5.2f",x1,x2);
     }

/* WHEN D<0 */
    else if(d<0)
    {
     printf("\n roots are imaginary and unequal::");
     d=-d;
     d=sqrt(d);
     x1=-b/2.0*a+d/2.0*a;
     x2=-b/2.0*a-d/2.0*a;
     printf("\n The roots are::");
     printf("\n(%5.2f)+i(%5.2f)",x1,x2);
     printf("\n(%5.2f)-i(%5.2f)",x1,x2);
     }
     getch();
   } /* END OF MAIN*/









