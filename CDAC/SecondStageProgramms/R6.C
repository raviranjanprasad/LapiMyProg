/*CREATE PASCAL TRIANGLE*/

void pascaltriangle(int n)
     {
     int p=1,q=0,r=0,i,x;
     while(q<n)
	  {
	  r=40-3*q;
	  for(i=0;i<=r;i++)
	     printf(" ");
	  for(x=0;x<=q;x++)
	     {
	     if((x==0)||(q==0))
		p=1;
	     else
		p=(p*(q-x+1))/x;
	     printf("%6d",p);
	     }
	  printf("\n");
	  q=q+1;
	  }
     }

void main()
     {
     int n;
     clrscr();
     printf("\nEnter the number of line in the pascal triangle:");
     scanf("%d",&n);
     pascaltriangle(n);
     getch();
     }
