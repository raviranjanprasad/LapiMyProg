	  /* USING POINTER PROGRAM TO
	   a.String comparision.
	   b.String cocatenate.
	   c.String copy.
	   d.String length.*/

#include<stdio.h>
#include<conio.h>
/* FUNCTION FOR STRING COMPARISION*/
   int  xstrcmp(char *p,char *q)
   {
   clrscr();
   while(*p)
    {
     if(*p==*q)
     {
      p++;
      q++;
      }
      else
       {
	return(*p-*q);
	}
      }
      return(0);
      }
/*FUNCTION TO CONCONATE Two STRING*/
 void  xstrcat(char *p,char *q)
 {
  clrscr();
   while(*p)
    p++;
    *p++=' ';

    while(*q)
     *p++=*q++;
     p='\0';

     }

 /*FUNCTION TO COPY A STRING TO OTHER*/
   void xstrcpy(char *p,char *q)
   {
    clrscr();
    while(*p)
    *q++=*p++;
    q='\0';
    }
/*FUNCTION TO FIND THE LENGTH OF THE STRING*/
  void xstrlen(char *p)
   {

    int len=0;
    clrscr();
    while(*p)
    {
     p++;
     len++;
     }
     printf("\n Length of the string is %d",len);
   }




/*MAIN FUNCTION */
void main()
{
 static char str1[50],str2[50],ch;
 char *p,*q;
 int flag=0,num;
 clrscr();
  printf("\n Enter the first string::");
  gets(str1);

 printf("\n Enter the second string::");
 gets(str2);
 p=str1;
 q=str2;

 do {
     printf("\n a.String comparision.");
     printf("\n b.String concanate.");
     printf("\n c.String copy.");
     printf("\n d.length of the string");
     printf("\n e.EXIT");
     printf("\n ENTER YOUR CHOICE::");
     scanf("%c",&ch);
     switch(ch)
     {
       case 'a':  clrscr();
		  num=xstrcmp(p,q);
		  printf("\n\ncomparision result %d",num);
		  break;

      case 'c':
		 xstrcpy(p,q);
		 puts(str2);
		  break;
      case 'b':
		xstrcat(p,q);
		 puts(str1);
		 break;

      case 'd':
		 xstrlen(p);
		 xstrlen(q);
		 break;
      case 'e':
	       flag=1;
	       break;
  /*   default :
	       printf("\n Wrong choice");*/
	   }

	 }while(!flag);
       getch();
       }