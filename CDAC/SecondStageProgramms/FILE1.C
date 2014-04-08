                        
					/* PROGRAM TO ENTRY DIFFERENT KIND OF DATA IN A FILE */

#include<stdio.h>
#include<conio.h>
void main()
{
 FILE *f1;
 char name[20];
 char regno[15];
 float mk1,mk2,mk3,avg;
 int i,n;
 clrscr();
printf("\n\t\t* PROGRAM TO ENTRY DIFFERENT KIND OF DATA IN A FILE*");

 /* OPENING THE FILE TO WRITE*/
  printf("\n open the file to write the contents");
 printf("\n ENTER THE NO OF RECORDS::");
  scanf("%d",&n);
  f1=fopen("TEST.DAT","w");
 for(i=1;i<=n;i++)
    {
     printf("\nenter the name,regno,mk1,mk2,mk3::");
     scanf("%s%s%f%f%f",name,regno,&mk1,&mk2,&mk3);

      avg=(mk1+mk2+mk3)/3.0;
     fprintf(f1,"%-10s%-8s%-8.2f%-8.2f%-8.2f%-8.2f\n",name,regno,mk1,mk2,mk3,avg);
     }

   /*CLOSING THE FILE AFTER WRITING INTO IT*/
   fclose(f1);

  /* REOPEN THE FILE FOR READING TEH CONTENTS */
   printf("\n--------------------------------------------------");
   printf("\nNAME      REGNO     MK1     MK2     MK3      AVG");
   printf("\n---------------------------------------------------");
   f1=fopen("TEST.DAT","r");
   for(i=1;i<=n;i++)
   {
   fscanf(f1,"%s%s%f%f%f%f",name,regno,&mk1,&mk2,&mk3,&avg);
   printf("\n");
   printf("\n%-10s%-10s%-8.2f%-8.2f%-8.2f%-8.2f",name,regno,mk1,mk2,mk3,avg);
    }

  /*RECLOSE THE FILE AFTER READING THE CONTENTS*/
  fclose(f1);

  getch();
  }
