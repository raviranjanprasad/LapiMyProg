#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/* STRUCTURE OF INVENTRORY RECORD*/
typedef struct invent_record
{
 char name[30];
 int number;
 float price;
 int quantity;
 }invent_record;
/* printf("\n\t\t*PROGRAM FOR INVENTORY RECORD*\n");*/

 /*FUNCTION TO APPEND THE ITEM IN THE FILE*/
   void append(invent_record *item, File *f)
    {
     printf("\n item name::");
      scanf("%s",item->name);
     printf("\n item number::");
      scanf("%d",&item->number);
      printf("\n item price::");
      scanf("%f",&item->price);
      printf("\n item quantity::");
      scanf("%d",&item->quantity);
      fprintf(f,"%s %d %f %d",item->name,item->number,item->price,item->quantity);
      }

 /*MAIN PROGRAMME*/
  void main()
  {
   invent_record *item;
   int flag;
   FILE *f1;
   char filename[30];
   long n;
   clrscr();
   printf("\n enter the file name::");
   scanf("%s",filename);

   /*OPEN THE FILE FOR APPEND A NEW ITEM*/
   f1=fopen(filename,"a+");
   do
    {
     append(&item,f1);
     printf(" enter 1 to append/0 to exit::");
     scanf("%d",&flag);
    /* if(flag)
      append(&item,f1); */
      }while(flag);

   /*CURRENT POSITION OF THE POINTER IN THE FILE*/
      n=ftel(f1);
      fclose(f1);
		  dz
 /* OPEN THE FILE TO READ THE DATA*/
    while(ftel(f1)<n)
    {
     fscanf(f1,"%s %d %f %d",item->name,&item->number,&item->price,&item->quantity);
     printf("%s\t%d\t%f\t%d\t",item->name,item->number,item->price,item->quatity);
     }
     fclose(f1);
     getch();
     }



