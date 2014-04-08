
			  /* PROGRAM TO SORT THE NAME BY LENGTH*/

#include<stdio.h>
#include<conio.h>
typedef struct
{
 char str[20];
 }name;

 /*FUNCTION TO INSERT NAMES*/
  void insert(name first[],int n)
   {
    int i;
    for(i=0;i<n;i++)
     {
      printf("\n Enter a name::");
      scanf("%s",first[i].str);
      }
     }

 /*DISPALY FUNCTION*/
   void display(name first[],int n)
    {
     int i;
     printf("\nNAME");
     for(i=0;i<n;i++)
      printf("-->%s",first[i].str);
      }
 /*FUNCTION TO SORT*/
   void sort(name first[],int n)
    {
      int i,j;
      name temp;
      for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
	if(strlen(first[i].str)>strlen(first[j].str))
	 {
	 temp=first[i];
	 first[i]=first[j];
	 first[j]=temp;
	 }
	}

      }


 /*VOID MAIN*/
 void main()
 {
   int n;
  name first[15];
   clrscr();
   printf("\n enter the no of name u want to insert::");
   scanf("%d",&n);
   insert(first,n);
    display(first,n);
   sort(first,n);
     printf("\nSORTED ");
     display(first,n);
   getch();
   }



