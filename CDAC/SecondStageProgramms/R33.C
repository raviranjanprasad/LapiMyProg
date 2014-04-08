#include<stdio.h>
#include<conio.h>
void main()
 {
  char str[20],str1[20];
  char *s,*p,c;
  clrscr();
  printf("\n enter the string:");
  gets(str);
  printf("\n enter the character to be deleted:");
  c=getche();
  s=str;
  p=str1;
  while(*s)
  {
   if(*s==c)
    s++;
  else
    *p++=*s++;
   }
   *p='\0';
   printf("\n the string after removal of charc:   ");
   puts(str1);
   getch();
   }
