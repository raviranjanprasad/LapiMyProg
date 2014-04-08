       /* PROGRAM TO PERFORM THE BINARY SEARCH IN A ARRY
	  TO FIND THE LOCATION OF A PARTICULAR ITEM BY USING
	  POINTER*/

 #include<stdio.h>
 #include<conio.h>

 /*FUNCTION TO FIND THE LOCATION BY BINARY SEARCH*/
 int binary_search(int a[],int beg,int end,int item)
 {
    int *p,mid;
     p=a;
     mid=(beg+end)/2;
     p=p+mid;
     if(item==*p)
      return(mid+1);
      else if(item<*p)
	{
	  end=mid-1;
	  binary_search(a,beg,end,item);
	  }
	  else if(item>*p)
	   {
	     beg=mid+1;
	     binary_search(a,beg,end,item);
	     }
	     else
	      return(0);
	  }

 /* MAIN FUNCTION*/
  void main()
  {
   int a[10],i,n,item,loc;
   clrscr();
   printf("\n Enter the no of elements in the array::");
   scanf("%d",&n);
   printf("\n Enter the element of the sorted array::");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   printf("\n Enter the item to be searched::");
   scanf("%d",&item);
   loc=binary_search(a,0,n,item);
   if(loc==0)
    printf("The item is not persent in the list");
   printf("The location of the element is %d::",loc);
   getch();
   }
