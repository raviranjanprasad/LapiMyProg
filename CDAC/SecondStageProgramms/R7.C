                   
				   /*PROGRAM TO FIND THE SUM OF THE SERIES
				      1+1/2+1/3+1/4+..................*/
         
/* FUNCTION FOR SERIES SUM */
  float sum(int n)
  {
   float s1=0.0;
   int i;
   for(i=1;i<=n;i++)
    s1=s1+1.0/(float)i;
    return(s1);
  }



/* MAIN FUNCTION */
void main()
 {
  int n;
  float s;
  clrscr();
  printf("\n enter the no of terms:");
  scanf("%d",&n);
  s=sum(n);
  printf("\n the sum of the series 1+1/2+1/3+1/4....up to %d term is %5.2f",n,s);
  getch();
 }