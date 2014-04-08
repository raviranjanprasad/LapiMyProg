            /*SUNBEAM P.N:33*/
			/*PROGRAM TO REMOVE ALL COMMENT IN THE FILE*/

#include<stdio.h>
#include<conio.h>
FILE *fs,*ft;
void incomment()
	   {
	     int c,d;
	     c=getc(fs);
	     d=getc(fs);
	      while(c!='*'||d!='/')
	       {
		 c=d;
		 d=getc(fs);
	       }
	    }
void main()
{

  int c,d;

  clrscr();
  if((fs=fopen("COMMENT.TXT","r"))==NULL)
   {
     printf("\n Unable to open the file COMMENT.TXT::");
     exit(1);
   }
   getch();
   if((ft=fopen("COMMENT1.TXT","w"))==NULL)
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
	   }
	     else
	      fprintf(ft,"%c",c);
	 }
	    fclose(fs);
	    fclose(ft);
	    printf("\n The new file is created");
	    getch();
       }
