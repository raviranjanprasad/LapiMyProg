#include<stdio.h>
#include<conio.h>
void main()
{
 int row,i,j, col,k;
 clrscr();
 printf("\n enter the no of rows::");
 scanf("%d",&row);
 printf("\n enter the no of cols::");
 scanf("%d",&col);
 for(i=1;i<=row;i++)
  {
  /* for(j=1;j<=col;j++)*/

     if((i!=1)&&(i!=row))
      {
       printf("%c",179);
	for(k=2;k<col;k++)
	 printf(" ");
	 printf("%c",179);
       }
       if(i==1)
	{
	 printf("%c",218);
	 for(k=2;k<col;k++)
	  printf("%c",196);
	  printf("%c",191);
	}
	if(i==row)
	 {
	  printf("%c",192);
	  for(k=2;k<col;k++)
	   printf("%c",196);
	   printf("%c",217);
	  }

	printf("\n");
      }
    getch();
  }