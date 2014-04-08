     /*REPERSENT RECORD IN TEH TABULAR FORM*/

#include<stdio.h>
#include<conio.h>
typedef struct invent
{
  char name[15];
  int number;
  float price;
  int quantity;
  }invent;

/*MAIN FUNCTION*/
  void main()
  {
    FILE *fp;
    invent item;
    char filename[15];
    char flag;
    long n;
    char another='Y';
    clrscr();
    printf("\n Enter the filename::");
    scanf("%s",filename);
    fp=fopen(filename,"w");
    do
      {
	 printf("\nItem name::");
	scanf("%s",item.name);
      printf("\n Item number::");
      scanf("%d",&item.number);
      printf("\nItem price::");
      scanf("%f",&item.price);
      printf("\n Quantity::");
      scanf("%d",&item.quantity);
      fprintf(fp,"\n%-15s%-8d%17.2f%-6d",item.name,item.number,item.price,item.quantity);
       printf("\n Item %s appended.",item.name);
       printf("\n Add another record(y/n)");
       another=getche();
       }while(another=='y');

       fclose(fp);
       clrscr();

   /*OPEN THE FILE FOR READ THE CONTENTS*/
     fp=fopen(filename,"r");

       if(fp==NULL)
       {
       puts("The file cannot be opened");
       fclose(fp);
	exit();
	}

     printf("\n-------------------------------------------");
     printf("\nNAME          NUMBER  PRICE        QUANTITY");
     printf("\n--------------------------------------------");

    while(fscanf(fp,"%s%d%f%d",item.name,&item.number,&item.price,&item.quantity)!=EOF)
	 printf("\n%-15s%-8d%-17.3f%-4d",item.name,item.number,item.price,item.quantity);


      fclose(fp);
      getch();
      }






