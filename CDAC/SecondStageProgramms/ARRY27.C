	    /* PROGRAM TO PRINT THE ARRY ELEMENTS AFTER A KEY
	       VALUE.i.e IF A[]=1 2 3 4 5 6 AND KEY=3 THEN
	       OUTPUT SHOULD BE A[]=4 5 6 1 2 3*/


#include<stdio.h>
#include<conio.h>
#define MAX 6
void main()
{
  static int arr1[10],arr2[10];
  int front1;
  int j,rear2;
  int key,i;
  clrscr();
  printf("\n Enter the elements of arry::");

  for(i=0;i<MAX;i++)
  scanf("%d",&arr1[i]);
  printf("\n Enter the key value::");
  scanf("%d",&key);
  for(i=0;i<MAX;i++)
   {
     if(key==arr1[i])
     {

      front1=i+1;
      break;
      }

      }
      rear2=0;

     while(rear2<MAX)
     {
       arr2[rear2]=arr1[front1];
       front1++;
       rear2++;
       if(front1==MAX)
	front1=0;
	}
	for(j=0;j<MAX;j++)
	   printf(" %d ",arr2[j]);

     getch();
    }