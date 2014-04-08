				    /*SUNBEAM P.N:29*/
		   /*PROGRAM THAT WILL READ EACH LINE IN THE FILE AND STORE IT IN ANOTHER FILE
		     WITH EACH LINE REVERSED*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 FILE *fp1,*fp2,*fp3;
 char ch;
 clrscr();
 if((fp1=fopen("F1.TXT","w"))==NULL)
  {
    printf("\n Unable to open the file F1.TXT::");
    exit(1);
   }
    printf("\n Enter the content of the file 1::");
   while((ch=getchar())!=EOF)
   {
    putc(ch,fp1);
    printf("%c",ch);
    }
  fclose(fp1);
  printf("\n");

  if((fp2=fopen("F2.TXT","w"))==NULL)
  {
    printf("\n Unable to open the file F2.TXT::");
    exit(1);
   }
    printf("\n Enter the content of the file 2::");
   while((ch=getchar())!=EOF)
   {
    putc(ch,fp2);
    printf("%c",ch);
    }
  fclose(fp2);
  printf("\n");

  fp1=fopen("F1.TXT","r");
  fp2=fopen("F2.TXT","r");
  fp3=fopen("F3.TXT","w");

   while((ch=fgetc(fp1))!=EOF)
     fputc(ch,fp3);

   while((ch=fgetc(fp2))!=EOF)
     fputc(ch,fp3);
     fclose(fp1);
     fclose(fp2);
     fclose(fp3);

   fp3=fopen("F3.TXT","r");
   printf("\n The contents of file1 and file2 are merged in to file3 as::");
    while((ch=fgetc(fp3))!=EOF)
     printf("%c",ch);
    fclose(fp3);

     getch();
   }

