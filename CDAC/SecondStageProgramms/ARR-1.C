
                    /*PROGRAM TO CONVERT THE OCTAL NO TO HEXADECIMAL*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

/*FUNCTION TO CONVERT OCTAL TO DECIMAL*/
 long convert1(long onum)
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
      char ch;
      int k,sum=0,dec=0,len;
      static int oct[15];
      int i=0,count,j=0,r;

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
		    hex[i]='D';
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


/*FUNCTION TO CONVERT HEXADECIMAL TO DECIMAl*/
       strrev(hex);
       len=strlen(hex);
       for(i=0;i<len;i++)
	{
	  ch=hex[i];
	  switch(ch)
	   {

	   case '0':
		    dec=0;
		    sum=sum+dec*pow(16,i);
		    break;

	   case '1':
		    dec=1;
		    sum=sum+dec*pow(16,i);
		    break;

	   case '2':
		    dec=2;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '3':
		    dec=3;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '4':
		    dec=4;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '5':
		    dec=5;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '6':
		    dec=6;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '7':
		    dec=7;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '8':
		    dec=8;
		     sum=sum+dec*pow(16,i);
		    break;

	   case '9':
		   dec=9;
		     sum=sum+dec*pow(16,i);
		    break;

	     case 'A':
		    dec=10;
		     sum=sum+dec*pow(16,i);
		    break;

	      case 'B':
		    dec=11;
		     sum=sum+dec*pow(16,i);
		    break;
	      case 'C':
		    dec=12;
		     sum=sum+dec*pow(16,i);
		    break;
	      case 'D':
		    dec=13;
		     sum=sum+dec*pow(16,i);
		    break;
	      case 'E':
		    dec=14;
		     sum=sum+dec*pow(16,i);
		    break;
	      case 'F':
		    dec=15;
		     sum=sum+dec*pow(16,i);
		    break;
	      }

	}
         printf("\n The decimal quivelent %d",sum);


/*COVERT THE DEC TO OCTAL*/
    i=0;
    count=0;
    while(sum>0)
    {
     r=sum%8;
     oct[i]=r;
     i++;
     sum=sum/8;
     count++;
     }
     printf("\nThe octal conversion of hexadecimal is::");
     for(j=count;j>=0;j--)
      {
       printf("%d",oct[j]);
       }
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