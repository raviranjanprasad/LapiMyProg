#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 7

/*FUNCTION TO FIND THE MEAN*/
float mean(float a[])
  {
  int i;
  float m,x=0.0;
  clrscr();
  for(i=0;i<MAX;i++)
     {
      x+=a[i];
     }
  m=x/(float)MAX;
  return(m);
  }

/*FUNCTION TO FIND MEDIAN*/
float median(float a[])
    {
    int i,j,med1;
    float temp;
    clrscr();
    printf("\nSorted data::");
    for(i=0;i<MAX;i++)
       {
       for(j=i+1;j<MAX;j++)
	   {
	   if(a[i]>a[j])
	     {
	     temp=a[i];
	     a[i]=a[j];
	     a[j]=temp;
	     }
	  }
	}
      for(i=0;i<MAX;i++)
	 printf("%4.2f->",a[i]);
      med1=(MAX +1)/2;
      return(a[med1-1]);
     }

/*FUNCTION FOR FINDING MODE*/
void mode(float a[])
	 {
	 float mod,min1,med1;
	 min1=mean(a);
	 med1=median(a);

	 mod=min1-3*(min1-med1);
	 printf("\nMODE=%5.3f",mod);
	 }
/*FUNCTION TO FIND VARIANCE*/
float variance(float a[])
	 {
	 float men1,sd1=0.0,sd2=0.0,sd;
	 int i;
	 clrscr();
	 men1=mean(a);
	 for(i=0;i<MAX;i++)
	    {
	    sd1+=pow((a[i]-men1),2);
	    sd2+=a[i]-men1;
	    }

	 sd=pow(sd1,2)/MAX-pow(sd2/MAX,2);
	 return(sd);
	 }
/*FUNCTION FOR STANDARD DEVIATION*/
float standard_deviation(float a[])
    {
    float var1,sd;
    var1=variance(a);
    sd=sqrt(var1);
    return(sd);
    }



/*MAIN FUNCTION*/
void main()
{
 int i,flag=1,choice;
 float a[MAX],m,med,var,sd;
 clrscr();
 printf("\n Enter the data::");
 for(i=0;i<MAX;i++)
 {
  printf("\n DATA->%d::",i+1);
  scanf("%f",&a[i]);
  }
  do
   {
     printf("\n 1.Mean");
     printf("\n 2.Median");
     printf("\n 3.Mode");
     printf("\n 4.varience");
     printf("\n 5.Standard deviation");
     printf("\n 6.EXIT");
     printf("\n Enter your choice::");
     scanf("%d",&choice);
     switch(choice)
     {
	case 1:
		m=mean(a);
                printf("\nMEAN=%6.3f",m);
		break;
	case 2:
		med=median(a);
		printf("\nMEDIAN=%5.3f",med);
		break;
	case 3:
		mode(a);
		break;
	case 4:
		var=variance(a);
		printf("\nVARIANCE=%5.3f",var);
		break;
	case 5:
		sd=standard_deviation(a);
		printf("\nSTANDARD DEVIATION=%5.3f",sd);
		break;
	case 6:
		flag=0;
		break;
      default:
		printf("\n WRONG CHOICE TRY AGAIN::");
	   }
	 }while(flag);
     getch();
    }

