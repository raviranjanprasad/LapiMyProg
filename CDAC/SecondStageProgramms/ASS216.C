#include<stdio.h>
#include<conio.h>
void main()
{
 int num,i,j;
 char s[10][20],temp[20];
 clrscr();
 printf("\n Enter the names of 10 students::");
 for(i=0;i<10;i++)
  {
   flushall();
  gets(s[i]);
  }
  for(i=0;i<9;i++)
   for(j=i;j<10;j++)
     {
      if(strcmp(s[j],s[i])>0)
       {
	 strcpy(temp,s[j]);
	 strcpy(s[j],s[i]);
	 strcpy(s[i],temp);
	 }
      }
    printf("\n The entered name in the back alphabetic order is::\n");
    for(i=0;i<10;i++)
    {
     puts(s[i]);
     printf("\n");
     }
     getch();
   }


