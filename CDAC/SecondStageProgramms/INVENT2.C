#include<stdio.h>
#include<conio.h>
typedef struct invent
{
 int record;
 char tool_name[20];
 int quantity;
 float cost;
 }invent;

 /* FUNCTION OF WRITE IN THE FILE*/
   void writerecord()
    {
    FILE *fp1;
    char yes_no='y';
    invent material;
    if((fp1=fopen("STORE1.DAT","wb+"))==NULL)
    {
     printf("\n unable to open the file store.txt ");
     getch();
     exit(1);
     }
     do
      {
       printf("\n Enter the record no::");
       scanf("%d",&material.record);
       printf("\n Enter the tool name::");
       scanf("%s",&material.tool_name);
       printf("\n Enter the quantity::");
       scanf("%d",&material.quantity);
       printf("\n Enter the cost::");
       scanf("%f",&material.cost);
       fwrite(&material,sizeof(material),1,fp1);
       printf("\n want to enter more data::(y/n)");
       yes_no=getche();
       }while(yes_no=='y');
      fclose(fp1);
    }

 /*FUNCTION TO READ FORM THE FILE*/
  void readrecord()
  {
    FILE *fp1;
    invent material;
    if((fp1=fopen("STORE1.DAT","rb+"))==NULL)
    {
     printf("\n Unable to open the file store1.dat::");
     getch();
     exit(1);
     }
     printf("\n---------------------------------------------");
     printf("\nRecord#    Tool Name       Quantity      cost");
     printf("\n----------------------------------------------");
     while((fread(&material,sizeof(material),1,fp1))>0)
     {
       printf("\n %-10d%-20s%-7d%-10.3f",material.record,material.tool_name,material.quantity,material.cost);
       }
    fclose(fp1);
    }
 /*FUNCTION TO SORT THE RECORD BY ROCORD NO*/
    void sortrecord()
    {
     FILE *fp1,*fp2;
     invent material,temp;
     int max;
     clrscr();
    if((fp1=fopen("STORE1.DAT","rb+"))==NULL)
    {
     printf("\n Unable to open the file store1.dat::");
     getch();
     exit(1);
     }
     printf("\n---------------------------------------------");
     printf("\nRecord#    Tool Name       Quantity      cost");
     printf("\n----------------------------------------------");
     fread(&material,sizeof(material),1,fp1);
     max=material.record;
     while((fread(&material,sizeof(material),1,fp1)>0)
      {
	if(material.record>max)
	  {
	    max=material;
	    temp=max;
	    max=material;
	    material=temp;
	    }
	 }
       fclose(fp1);
       readrecord();
       }







/*VOID MAIN*/
void main()
 {
  int flag=1,i;
  clrscr();
  do
    {
      printf("\n 1.write a record in the file.");
      printf("\n 2.read form the file.");
      printf("\n 3.update the file.");
      printf("\n 4.delete a record from the file");
      printf("\n 5.EXIT");
      printf("\n ENTER YOUR CHOICE::");
      scanf("%d",&i);
      switch(i)
       {
	 case 1:
		writerecord();
		break;
	 case 2:
		readrecord();
		break;
	 case 3:
		sortrecord();
		break;
	/* case 4:
		deletrecord();
		break;*/
	 case 5:
		flag=0;
		break;
	 }
	}while(flag);
      getch();
     }






