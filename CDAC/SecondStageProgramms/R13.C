
          /*PROGRAM TO TRANSPOSE THE MATRIX*/
void main()
{
  int i,j,n,m,a[10][10],b[10][10];
  clrscr();
  printf("\n enter no of rows of matrix::");
  scanf("%d",&n);
  printf("\n enter no of coloumn of matrix::");
  scanf("%d",&m);
  printf("\n enter the matrix\n");
  for(i=0;i<n;i++)
   for(j=0;j<m;j++)
    scanf("%d",&a[i][j]);

    printf("\n The transpose of the given matrix is::\n");
     for(i=0;i<m;i++)
      for(j=0;j<n;j++)
	 b[i][j]=a[j][i];

      for(i=0;i<m;i++)
       {
	for(j=0;j<n;j++)
	 printf("%5d",b[i][j]);
	 printf("\n");
       }
     getch();
    }


