		     /*
		      program  to  print

		      z y x w v w x y z
			    z y x w x y z
			      z y x y z
			        z y z
			          z */

 #include<stdio.h>
 #include<conio.h>
   void main()
   {
    int i,j,k,p,ch,m,t,n;
    clrscr();
    printf("\nEnter the no of rows::");
    scanf("%d",&n);

    for(i=0;i<n;i++)
     {
       for(j=1;j<=30+i;j++)
	printf(" ");
	k=(2*n-2*i);
	 t=k/2;
	 ch=90;
	 for(m=1;m<=t;m++)
	  {
	  printf("%c",ch);
	  ch=ch-1;
	   }
	   ch=ch+1;
	  for(p=m+1;p<=k;p++)
	   {
	    ch=ch+1;
	    printf("%c",ch);
	    }
	    printf("\n");
	  }
       getch();
      }



