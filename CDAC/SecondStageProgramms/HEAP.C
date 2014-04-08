	      /* PROGRAM FOR THE HEAP SORT */

#include<stdio.h>
#include<conio.h>
#define MAX 7;
/* FUNCTION FOR THE HEAP SORT*/
  void heapsort(int a[],int n)
   {
    int i,temp;
    heapify(a,n);
    for(i=n;i>1;i--)
    {
     temp=a[1];
     a[1]=a[i];
     a[i]=temp;
     downheap(a,1,i-1);
     }
    }
/* FUNCTION TO HEAPIFY*/
  void heapify(int a[],int n)
  {
   int i,index;
   index=n/2;
   for(i=index;i>=1;i--)
    downheap(heap,i,n);
  }
/* FUNCTION FOR DOWNHEAP*/
 void downheap(int a[],int start,int finish)
  {
   int index,lchild,rchild,maxmin,temp;
   lchild=2*start;
   rchild=lchild+1;
   if(lchild<=finish)
    {
      maximum=a[lchild];
      index=lchild;
      if(rchild<=finish)
       {
	 if(a[rchild]>maximum)
	  {
	   maximum=a[rchild];
	   index=rchild;
	   }
	 }
      if(heap[start]<heap[index])
      {
       temp=heap[start];
       heap[start]=heap[index];
       heap[index]=temp;
       downheap(heap,index,finish);
       }
     }
  }


/* MAIN FUNCTION*/
void main()
 {
  int a[MAX],i,n;
  clrscr();
  printf("\n Enter the elements of the array::");
  for(i=1;i<=MAX;i++)
   {
   printf("\n enter a number::");
   scanf("%d",&a[i]);
   }
  for(i=1;i<=MAX;i++)
   {
   printf("\n The elements of the array is::");
   printf(" %d ",a[i]);
   }
   heapsort(a,MAX);
   getch();
 }

