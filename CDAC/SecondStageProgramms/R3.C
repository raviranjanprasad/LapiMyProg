                    /*PROGRAM TO DELETE A PARTICULAR CAHRACTER FORM A STRING AND 
					              THEN REARRANGE THE STRING*/

#include<stdio.h>
#include<conio.h>
/* FUCTION TO REMOVE THE CHAR AND REARRANGE THE STRING*/
void rearange(char *s,char c)
 {
  char str1[20],*p;
  p=str1;
  while(*s)
   {
     if(c==*s)
       s++;
      else
       *p++=*s++;
    }
   *p='\0';
   printf("\n the string after removal of character:");
   puts(str1);
   }

/* MAIN FUNCTION*/
void main()
{
 char *s,str[20],ch;
 clrscr();
 printf("\n enter the string of choice:");
 gets(str);
 printf("\n enter the character of ur choice:");
 ch=getche();
 s=str;
 rearange(s,ch);
 getch();
 }