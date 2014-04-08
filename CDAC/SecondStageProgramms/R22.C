
              /* PROGRAM OF FILE RECORD PF A PERSON WITH FIRSTNAME AND LASTNAME*/
#include<stdio.h>
#include<conio.h>
typedef struct record
{
 char lastname[15];
 char firstname[15];
 char age[10];
  }record;


 /* FUNCTION TO WRITE IN THE FILE*/
  void writefile()
    {
     FILE *f1;
     record person;
     char yes_no='y';
     clrscr();
       if((f1=fopen("nameage.dat","wb+"))==NULL)
	{
	   printf("\n Unable to open nameage.dat");
	   exit(1);
	 }
     do
      {
       printf("\n Enter last name::");
       scanf("%s",person.lastname);
       printf("\n Enter first name::");
       scanf("%s",person.firstname);
       printf("\n Enter age::");
       scanf("%s",person.age);
       fwrite(&person,sizeof(person),1,f1);
       printf("any more data(y/n)::");
       yes_no=getche();
      } while(yes_no=='y');

     fclose(f1);
   /*  return(f1);*/
  }

/*FUNCTION TO READ FORM A FILE */
 void readfile()
  {
   FILE *f1;
   record person;
   clrscr();
   if((f1=fopen("nameage.dat","rb"))==NULL)
    {
     printf("\n Unable to read form the file nameage.dat:");
     exit(1);
     }
    printf("\n--------------------------");
    printf("\nLASTNAME   FIRSTNAME   AGE");
    printf("\n--------------------------");
    while(fread(&person,sizeof(person),1,f1)>0)
    {
      printf("\n%-11s%-12s%-8s",person.lastname,person.firstname,person.age);
       }
      fclose(f1);
     }

 /* FUNCTION TO UPDATE A FILE*/
  void updatefile()
   {
     FILE *f1;
     int flag=0;
     record person;
     char name[15];
     if((f1=fopen("nameage.dat","rb+"))==NULL)
     {
      printf("\n Unable to open nameage.dat file");
      exit(1);
      }
      printf("\n Enter the last name of person whoes record is to be updated::");
      scanf("%s",name);
      while((fread(&person,sizeof(person),1,f1))>0)
      {
	if(strcmp(person.lastname,name)==0)
	{
	flag=1;
	printf("Enter the new lastname::");
	scanf("%s",person.lastname);
	printf("\nEnter the first name::");
	scanf("%s",person.firstname);
	printf("\n Enter the age::");
	scanf("%s",person.age);
	fseek(f1,-(long)sizeof(person),1);
	fwrite(&person,sizeof(person),1,f1);
	}
      }
      if(!flag)
       printf("No information");
     fclose(f1);
     }

 /*FUNCTION TO DELETE A FILE*/
  void deletefile()
  {
   FILE *f1,*ftp;
   char name[15];
   record person;
   char yes_no='y';
   do
   {
   if((f1=fopen("nameage.dat","rb+"))==NULL)
   {
    printf("\n Unable to open file::");
    exit(1);
    }
    ftp=fopen("tmp.dat","wb+");
     printf("\n Enter the last name::");
    scanf("%s",name);
    while((fread(&person,sizeof(person),1,f1))>0)
     {
       if(strcmp(person.lastname,name)!=0)
	  fwrite(&person,sizeof(person),1,ftp);

      }
      fclose(f1);
      fclose(ftp);
      remove("nameage.dat");
      rename("tmp.dat","nameage.dat");
      f1=fopen("nameage.dat","rb+");
      while((fread(&person,sizeof(person),1,f1))>0)
       {
	fwrite(&person,sizeof(person),1,f1);
	}
    printf("\nThe record deleted::");
    printf("\n Do you want to delete more data::(y/n)");
    yes_no=getche();
    }while(yes_no=='y');
  }


 /* FUNCTION TO APPEND THE NEW RECORD IN THE DATA*/
  void appendfile()
    {
     FILE *f1;
     record person;
     char yes_no='y';
     clrscr();
       if((f1=fopen("nameage.dat","ab+"))==NULL)
	{
	   printf("\n Unable to open nameage.dat");
	   exit(1);
	 }
     do
      {
       printf("\n Enter last name::");
       scanf("%s",person.lastname);
       printf("\n Enter first name::");
       scanf("%s",person.firstname);
       printf("\n Enter age::");
       scanf("%s",person.age);
       fwrite(&person,sizeof(person),1,f1);
       printf("any more data(y/n)::");
       yes_no=getche();
      } while(yes_no=='y');

     fclose(f1);
  }

 /* MAIN FUNCTION*/
void main()
 {
  FILE *f1;
  int flag=1,i;
  clrscr();
  do
    {
      printf("\n\t\t*MENU DRIVEN FOR FILE PERSON*");
      printf("\n1.Write into the file.");
      printf("\n2.Read form the file.");
      printf("\n3.Update the record of the file.");
      printf("\n4.Delet the record of the file.");
      printf("\n5.Append a new record in the file");
      printf("\n6.EXIT");
      printf("\nEnter your choice::(1/2/3/4/5/6):");
      scanf("%d",&i);
      switch(i)
       {
	case 1:
	       writefile();
	       break;
       case 2:
	       readfile();
	       break;
      case 3:
	       updatefile();
	       break;
     case 4:
	      deletefile();
	      break;
      case 5:
	      appendfile();
	      break;
      case 6:
	      flag=0;
	      break;
      default:
	      printf("\n you have entered wrong choice::%d try again",i);
	  }
      } while(flag);
   getch();
   }





