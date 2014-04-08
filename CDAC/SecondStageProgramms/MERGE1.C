#include<stdio.h>
#include<conio.h>
#include<string.h>

 typedef struct address
 {
   char name[30];
   char email[30];
   char subject[30];
  }address;
void main()
{
 int i,num,n;
 char ch1;
address address1[10];
FILE *fp,*fp1,*fp2;
clrscr();
 if((fp=fopen("merge.txt","w"))==NULL)
 {
   printf("\n Unable to open the file merge.txt::");
   exit(1);
  }
  printf("\n Enter the number of addresses::");
  scanf("%d",&num);
   for(i=0;i<num;i++)
    {
      printf("\n Enter the name::");
      scanf("%s",&address1[i].name);
      fprintf(fp,"%s\n",address1[i].name);
      printf("\n Enter the email::");
      scanf("%s",&address1[i].email);
      fprintf(fp,"%s\n",address1[i].email);
      printf("\n Enter the subject::");
      scanf("%s",&address1[i].sxubject);
      fprintf(fp,"%s\n",address1[i].subject);
     }
       fclose(fp);

  if((fp1=fopen("merge1.txt","r"))==NULL)
 {
   printf("\n Unable to open the file merge1.txt::");
   exit(1);
  }
  if((fp2=fopen("merge2.txt","w"))==NULL)
 {
   printf("\n Unable to open the file merge2.txt::");
   exit(1);
  }
     for(i=0;i<num;i++)
      {
	fprintf(fp2,"NAME::%s\n",address1[i].name);
	fprintf(fp2,"EMAIL::%s\n",address1[i].email);
	fprintf(fp2,"SUBJECT::%s\n",address1[i].subject);
	fprintf(fp2,"\n");


	if((fp1=fopen("merge1.txt","r"))==NULL)
      {
	printf("\n Unable to open the file merge1.txt::");
	exit(1);
      }      fprintf(fp2,"\n MATTER::");
	     while((ch1=fgetc(fp1))!=EOF)
	    fputc(ch1,fp2);
	    fprintf(fp2,"\n");
	    fprintf(fp2,"******************************************************************************************");
	    fprintf(fp2,"\n");

	 fclose(fp1);
     }

	 fclose(fp);
	 fclose(fp2);
	 getch();
  }


