
                 /*PROGRAM TO TEST THE MAGIC SQUARE*/
 
 void main()
 {
  int i,j,a[10][10],n,flag=1,sum=0,sumr=0,sumc=0,sumld=0;
  clrscr();
  printf("\n enter the order of the matrix::");
  scanf("%d",&n);
  printf("\n\n enter the element of the matrix::\n");
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);


   /*sum of right diagonal*/
    for(i=0;i<n;i++)
     sum+=a[i][i];
    /*test for the magic squre*/
     while(flag)
      {
       /*Test for the left diagonal*/
	for(i=0;i<n;i++)
	  sumld+=a[i][n-1-i];
	  if(sum!=sumld)
	   flag=0;

       /*Test for the rows*/
	 for(i=0;i<n;i++)
	  {
	     sumr=0;
	   for(j=0;j<n;j++)
	     sumr+=a[i][j];
	      if(sumr!=sum)
	       flag=0;
	   }
	 /*Test for the coloum*/
	  for(i=0;i<n;i++)
	   {
	    sumc=0;
	    for(j=0;j<n;j++)
	     sumc+=a[j][i];
	      if(sumc!=sum)
	      flag=0;
	    }
	  break;
       }
       if(flag)
	printf("\n the entered matrix was a magic matrix");
	else if(!flag)
	 printf("\n the entered matrix was not a magic matrix");
	 getch();
     }


