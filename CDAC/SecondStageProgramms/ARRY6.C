		/* PROGRAM FOR THE SORTING OF A 4*4 MATRIX*/

#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,m,n,a[10][10],temp,k,l;
 clrscr();
 printf("\n enter the no of rows and coloum of a matrix::");
 scanf("%d%d",&m,&n);
 printf("\n Enter the element of the matrix.\n");
   for(i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
	{
	scanf("%d",&a[i][j]);
	 }
       }

 for(i=0;i<m;i++)
 {
   for(j=0;j<n;j++)
    {
    for(k=0;k<m;k++)
     {
     for(l=0;l<n;l++)
      {
       if(a[i][j]<a[k][l])
	{
	 temp=a[i][j];
	 a[i][j]=a[k][l];
	 a[k][l]=temp;
	 }
	}
       }
      }
     }

     printf("\nTHE SORTED MARTIX IS\n");
     for(i=0;i<m;i++)
     {
       for(j=0;j<n;j++)
	{
	 printf("%d ",a[i][j]);
	 }
	 printf("\n");
       }
       getch();
     }

