#include<stdio.h>
#include<conio.h>
#include<string.h>

struct name
{
 char name[40];
 char email[40];
 char subject[40];
 };
 void main()
 {
 struct name n;
 FILE *fp1,*fp2;
 char str[80];
 clrscr();
 strcpy(n.name,"Anupama Bhat\n");
 strcpy(n.email,"anupama_ansh@yahoo.co.in\n");
 strcpy(n.subject,"Hi\n");
 fp1=fopen("d:\\tc\\abc.txt","r");
 fp2=fopen("xyz.txt","w");
  fgets(str,80,fp1);

  strcat(str,n.name);
  fputs(str,fp2);

  fgets(str,80,fp1);
  strcat(str,n.email);
  fputs(str,fp2);

   fgets(str,80,fp1);
  strcat(str,n.subject);
  fputs(str,fp2);

  fputs("\n\n",fp2);
  while(fgets(str,80,fp1))
  {
  fputs(str,fp2);
  }
  fcloseall();
  }


