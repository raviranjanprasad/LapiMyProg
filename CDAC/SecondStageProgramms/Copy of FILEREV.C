#include<stdio.h>
#include<conio.h>
void main()
{
 FILE *f1,*f2;
 char line[30][30],ch;
 int row=0,col=0,i;
 clrscr();
/* if((f1=fopen("SOURCE.TXT","w"))==NULL)
  {
   printf("\n Unable to open the file::SOURCE.TXT");
   getch();
   exit(1);
   }
   printf("\n Enter the content of the file::");
   while((ch=getche())!=EOF)
   {
    fputc(ch,f1);
    }
    fclose(f1);*/
    if((f1=fopen("SOURCE.TXT","r"))==NULL)
    {
     printf("\n Unabel to open the file::SOURCE.TXT");
     getch();
     exit(1);
     }
    if((f2=fopen("TARGET.TXT","w"))==NULL)
    {
     printf("\n Unabel to open the file::TRRGET.TXT");
     getch();
     exit(1);
     }
/*     printf("\n Enter the content of the file SOURCE.TXT::\n");*/
     while((ch=fgetc(f1))!=EOF)
     {
      if(ch!='\n')
       {
	 line[row][col]=ch;
	 col++;
	 }
	 else
	  {
	   line[row][col]='\0';
	   row++;
	   col=0;
	   }
	 }
       if(ch==EOF)
	line[row][col]='\0';
	for(i=row;i>=0;i--)
	    {
	      fprintf(f2,"%s",line[i]);
	      fprintf(f2,"\n");
	      }
	  fclose(f2);
	  fclose(f1);
	  getch();
      }


