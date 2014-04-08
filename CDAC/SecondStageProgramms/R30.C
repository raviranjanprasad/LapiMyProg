
                        /*PROGRAM TO CALCULATE THE COMPUND INTEREST FACTOR F/A
						 FOR DIFFERENT INTERSET RATES AND FOR n YEARS*/

void main()
{
 float p;
 int n,k,j;
 float i,pro,intrest,intr;
 clrscr();
 printf("\n enter the principal value\n");
 scanf("%f",&p);
 printf("\n enter the number of years\n");
 scanf("%d",&n);
 printf("\ni/year:-->");
 i=4;
 while(i<=6)
  {
   printf("  %3.1f       ",i);
   i=i+0.5;
  }
  printf("\n");
  printf("\n");

   for(k=1;k<=n;k++)
  {
   printf("\n %d    ",k);
   for(i=4;i<=6;i=i+0.5)
     {
      intrest=(1+i/100.0);
      intr=1.0;
      for(j=1;j<=k;j++)
       intr=intr*intrest;
       pro=p;
       pro=pro*intr;
       printf("     %7.2f",pro);
    }
    printf("\n");
  }
    getch();
}


