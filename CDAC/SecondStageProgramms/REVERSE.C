#include<stdio.h>
#include<conio.h>
void main(int argc,char *argv[])
{
 FILE *f1,*f2;
 int i=0;
 char line[80],ch;
 clrscr();
 if(argc!=3)
 {
  printf("\n insufficent data::");
  getch();
  exit(1);
  }
  if((f1=fopen(argv[1],"r"))==NULL)
  {
   printf("\n Unable to open the SOURCE.TXT file::");
   getch();
   exit(1);
   }
  if((f2=fopen(argv[2],"w"))==NULL)
  {
   printf("\n Unable to open the SOURCE.TXT file::");
   getch();
   exit(1);
   }
   while((ch=fgetc(f1))!=EOF)
    {
      if(ch!='\n')
       line[i++]=ch;
       else
	{
	 line[i]='\0';
	 i=0;
	 fprintf(f2,"%s",strrev(line));
	 fprintf(f2,"\n");
	 }
      }
      if(ch==EOF)
      {
       line[i]='\0';
       fprintf(f2,"%s",strrev(line));
       }
     fclose(f1);
     fclose(f2);
     getch();
     }