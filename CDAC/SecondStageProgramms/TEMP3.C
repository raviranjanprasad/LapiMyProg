#include<stdio.h>
#include<conio.h>
struct person
 {
  char lastname[15];
  char firstname[15];
  char age[4];
  }record;

void write()
 {
  FILE *fp1;
  int flag=1;/*char ch1='y';*/
  clrscr();
  fp1=fopen("nameage.dat","wb+");
  if(fp1==NULL)
   {
    printf("Uanble To Open");
    exit(1);
   }
  while(flag/*ch1=='y'*/)
  {
    printf("\nEnter Last Name::");
  scanf("%s",record.lastname);
  printf("Enter First Name::");
  scanf("%s",record.firstname);
  printf("Enter Age");
  scanf("%s",record.age);
  fwrite(&record,sizeof(record),1,fp1);
  printf("Want To Add more Press 1or 0::");
  scanf("%d",&flag/*ch1=getche();*/);
  }
  fclose(fp1);
 }


void main()
 {
  int flag=1,i;
  clrscr();
do
 {
  printf("\n******MENU FOR NAMEAGE.DAT FILE********");
  printf("\n{1} PRESS 1 TO ENTER DIFFERENT PARAMETERS");
  printf("\n{4} PRESS 4 TO EXIT");
  printf("\n Enter your choice::");
  scanf("%d",&i);
switch(i)
  {
   case 1:
	     write();
	     break;
   case 4:
	     flag=0;
	     break;
   default:
	     printf("Wrong Selection");

   }
 }while(flag);
 getch();
}
/* FUNCTION TO WRITE IN THE FILE
 write()
 {
  FILE *fp1;
  char ch1='y';
  clrscr();
  fp1=fopen("nameage.dat","wb+");
  if(fp1==NULL)
   {
    printf("Uanble To Open");
    exit();
   }
  while(ch1=='y')
  {
    printf("\nEnter Last Name::");
  scanf("%s",record.lastname);
  printf("Enter First Name::");
  scanf("%s",record.firstname);
  printf("Enter Age");
  scanf("%s",record.age);
  fwrite(&record,sizeof(record),1,fp1);
  printf("Want To Add more Press 'y'or 'n'::");
  ch1=getche();
  }
  fclose(fp1);
 } */
