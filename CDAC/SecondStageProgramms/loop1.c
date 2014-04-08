#include<stdio.h>
#include<conio.h>
#include<math.h>
/*POWER FUNCTION*/
/* int pow(int n,int j)
  {
    int val=1;
    int i;
    if(j==0)
     return(val);
     else
       for(i=1;i<=j;i++)
	 val=n*val;
      return(val);
       }*/

/*FUNCTION TO CONVERT OCTAL TO DECIMAL*/
 int convert1(long onum)
  {
    int dnum1=0,r;
    int i=0;
    while(onum>0)
     {
      r=onum%10;
      dnum1=dnum1+r*pow(8,i);
      onum=onum/10;
      i=i+1;
      }
    return(dnum1);
   }

/* FUNCTION TO CONVERT THE DECIMAL VALUE IN HEXADECIMAL*/
   void convert2(long dnum)
    {
      static char hex[10];
      int k;
      int i=0;
      while(dnum>0)
       {
	k=dnum%16;
	   switch(k)
	    {
	   case 0:
		    hex[i]='0';
		    break;

	   case 1:
		    hex[i]='1';
		    break;

	   case 2:
		    hex[i]='2';
		    break;

	   case 3:
		    hex[i]='3';
		    break;

	   case 4:
		    hex[i]='4';
		    break;

	   case 5:
		    hex[i]='5';
		    break;

	   case 6:
		    hex[i]='6';
		    break;

	   case 7:
		    hex[i]='7';
		    break;

	   case 8:
		    hex[i]='8';
		    break;


	   case 9:
		    hex[i]='9';
		    break;

	     case 10:
		    hex[i]='A';
		    break;

	      case 11:
		    hex[i]='B';
		    break;
	       case 12:
		    hex[i]='C';
		    break;
	      case 13:
		    break;
	      case 14:
		    hex[i]='E';
		    break;
	      case 15:
		    hex[i]='F';
		    break;
	      }
	dnum=dnum/16;
	i++;
      }
	strrev(hex);
	printf("\n The hexadecimal form::");
	printf("%s",hex);
    }




/* FUNCTION MAIN*/
void main()
 {
  long onum,dnum;
  clrscr();
  printf("\n Enter a octal number::");
  scanf("%ld",&onum);
  dnum=convert1(onum);
  printf("decimal equvelent::%d",dnum);
   convert2(dnum);
  getch();
  }
