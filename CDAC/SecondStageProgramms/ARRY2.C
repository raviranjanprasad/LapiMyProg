
		   /*PROGRAM TO FIND OUT THE NO OF OCCURANCE
		   OF A STRING1 IN ANOTHER STRING2*/

#include<stdio.h>
#include<conio.h>
void main()
 {
  char str1[50],str2[50],*s,*p,*q;
  int count=0,flag=0;
  clrscr();
  printf("\n enter the string::");
  gets(str1);
  printf("\n enter the string two::");
  gets(str2);
  s=str1;
  p=str2;

 while(*s)
   {
    q=p;
    while(*q)
    {
     if(*s==*q)
     {
      flag=1;
      s++;
      q++;
      }
     else
      {
	flag=0;
	s++;

	}
      }
      if(flag)
	count=count+1;
      q='\0';
    s++;
    }
    printf("The number of occurance of %s in %s is %d",str2,str1,count);
     getch();
   }








