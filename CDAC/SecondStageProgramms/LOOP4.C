	       /*PROGRAM FOR TIME STRUCTURE*/

#include<stdio.h>
#include<conio.h>
typedef struct time
 {
  int hour;
  int minute;
  int second;
  }time;

 /* FUNCTION TO UPDATE THE TIME*/
 void update(time t)
 {
   printf("\nhh-->0-23");
   printf("\nmm-->0-59");
   printf("\nss-->0-59");
     printf("\nEnter the time in the format of hh:mm:ss");
   scanf("%d%*c%d%*c%d",&t.hour,&t.minute,&t.second);
   if(t.hour>23||t.minute>59||t.second>59)
    {
     printf("You have entered wrong time format::");
      return ;
      }
    t.second=t.second+30;
    if(t.second>59)
     {
      t.minute=t.minute+1;
      t.second=t.second-60;
      }
      t.minute=t.minute+1;
    if(t.minute>59)
      {
	t.hour=t.hour+1;
	t.minute=t.minute-60;
	}
	if(t.hour>23)
	 t.hour=t.hour-24;
	 printf("The updated time is::");
	printf("%d:%d:%d",t.hour,t.minute,t.second);
    }


/*MAIN FUNCTION*/
  void main()
  {
   time t;
   clrscr();
   update(t);
   getch();
   }

