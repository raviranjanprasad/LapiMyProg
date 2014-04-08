#include<stdio.h>
#include<conio.h>
FILE *fs,*ft;
void main()
{
 int c,d;
 clrscr();
 if((fs=fopen("COMMENT.TXT","r"))==NULL)
  {
   printf("\n unable to open the file COMMENT.TXT::");
   exit(1);
   }
   if((ft=fopen("COMMENT.TXT","w"))==NULL)
   {
     printf("\n Unable to open the file COMMENT.TXT::");
     exit(1);
     }
     while((c=getc(fs))!=EOF)
      {
       if(c=='/')
	{
	 if((d=getc(fs))=='*')
	  incomment();
	  else
	   {
	    fprintf(ft,"%c",c);
	    fprintf(ft,"%c",d);
	    }
