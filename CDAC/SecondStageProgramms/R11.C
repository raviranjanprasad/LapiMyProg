
                   /*PROGRAM TO CONVERT 'from' TO 'to' IN THE STRING*/

#include<stdio.h>
#include<conio.h>
void main()
 {
  char str1[50],str2[50],*s,*p,*q;
  int i;
  clrscr();
  printf("\n enter the string::");
  gets(str1);
  s=str1;
  p=str2;
  while(*s)
   {
    q=s;
    if(*s=='f'||*s=='F')
     {
      s++;
      if(*s=='r')
       {
	s++;
	if(*s=='o')
	 {
	  s++;
	  if(*s=='m')
	   {
	    *p++='t';
	    *p++='o';
	    }
	   else
	     {
	     for(i=0;i<=3;i++)
	     *p++=*q++;
	     }
	  }
	 else
	  {
	   for(i=0;i<=2;i++)
	   *p++=*q++;
	  }
	}
       else
	  {
	   for(i=0;i<=1;i++)
	   *p++=*q++;
	   }
	}
    else
	*p++=*s;
	 s++;
   }
     *p='\0';
     printf("\n\n                   ");
     puts(str2);
     getch();
     }







