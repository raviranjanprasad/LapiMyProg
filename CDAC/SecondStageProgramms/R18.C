
                             /*CHILDREN GAMES OF MULTIPLECATION*/

/* FUNCTION RANDOM*/
 void rand(int num1,int num2)
  {
      int num,c;
	c=num1*num2;
  sos:   printf("\n The %d times %d is::",num1,num2);
	 scanf("%d",&num);
	if(c==num)
	printf("\nVery Good");
	else
	 {
	 printf("\nSorry Wrong Answer Try again");
	 goto sos;
	 }
     }




/* FUNCTION MAIN */
void main()
{
 int flag=0,i,num1=0,num2=0;
 clrscr();
 do
 {
  printf("\n ************MENU*******************");
  printf("\n 1.Want to check your mathematics.");
  printf("\n 2.Exit.");
  printf("\n Enter your choice: 1 or 2::");
  scanf("%d",&i);
  switch(i)
   {
    case 1:for(num1=3;num1<=9;num1=num1+2)
	   {
	    for(num2=2;num2<=9;num2=num2+3)
	      rand(num1,num2);
	      }
	       break;
    case 2:
	   flag=1;
	   break;
     default:
	    printf("\n Wrong choice:Try again::");
      }
    }while(!flag);
   getch();
   }