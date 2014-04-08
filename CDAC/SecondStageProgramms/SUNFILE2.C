                    /*SUNBEAM P.N:28*/
					/*REVERSE EACH LINE IN A FILE */

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 FILE *fp,*fp1;
 int i=0;
 char ch,line[30];
 clrscr();
 if((fp=fopen("Rev.TXT","r"))==NULL)
 {
  printf("\n The file Rev.TXT is unable to open::");
  exit(1);
  }
  if((fp1=fopen("Rev1.TXT","w"))==NULL)
   {
    printf("\n The file Rev1.TXT is unable to open::");
    exit(1);
    }
    while((ch=fgetc(fp))!=EOF)
     {
       if(ch!='\n')
	{
	   line[i]=ch;
	   i++;
	 }
	else if(ch=='\n')
	  {
	   line[i]='\0';
	   fprintf(fp1,"%s",strrev(line));
	   fprintf(fp1,"\n");
	   i=0;
	  }
      }
	 if(ch==EOF)
	  {
	   line[i]='\0';
           fprintf(fp1,"%s",strrev(line));
	  }
	fclose(fp);
	fclose(fp1);
	getch();
      }


