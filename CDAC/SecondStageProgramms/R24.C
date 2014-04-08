
               /*PROGRAM TO ENCODE AND DECODE A FIVE LETTER WORD*/
#include<stdio.h>
#include<conio.h>
void main()
{
 char ch,k,c[5];
 int i;
 clrscr();
 printf("\n Enter five character::");
 for(i=0;i<5;i++)
 {
  ch=getch();
  c[i]=ch;
  k=ch-30;
  putch(k);
  }
  printf("\n The actual word was::");
  for(i=0;i<5;i++)
   printf("%c",c[i]);
   getch();
   }

