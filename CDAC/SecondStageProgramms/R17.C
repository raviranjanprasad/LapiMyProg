
			/*         PROGRAM OF STACK
		      PUSH,POP,INTERCHANGE TOP TWO ELEMENTS
						   */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct stack
 {
   int info;
   struct stack *link;
  }stack;

  /* DISPLAY FUNCTION*/
  void display(stack *s)
   {
    while(s!='\0')
    {
     printf("\n| %d|",s->info);
     s=s->link;
    }
  }


/* PUSH THE ELEMENT IN THE STACK*/
 stack *push(stack *s,int n)
 {
  int i;
  stack *new;
  for(i=1;i<=n;i++)
  {
  new=(stack*)malloc(sizeof(stack));
  printf("\n enter an item::");
  scanf("%d",&new->info);
  new->link=s;
  s=new;
  }
  return(s);
 }
 /*Fucntion display top element of the stack*/
  void printtop(stack *s)
   {
     int item;
      item=s->info;
    printf("\n The top element of the stack is::%d",item);
    }
/* FUNCTION TO DUPLICATE THE TOP ELEMENT*/
    stack *duplicate(stack *s)
     {
	   stack *new;
	   int num;
	    num=s->info;
	    new=(stack*)malloc(sizeof(stack));
	    new->info=num;
	    new->link=s;
	    s=new;
	    return(s);
	 }

  /* Function to swap two element */
   stack *swaptoptwo(stack *s)
    {
     stack *t1,*t2;
     int temp;
     t1=s;
     t2=s->link;
     temp=t1->info;
     t1->info=t2->info;
     t2->info=temp;
     return(s);
    }
/* MAIN FUNCTION */
void main()
 {
 int i,flag=1,n,num;
  stack *s,*new;
  char yes_no='y';
   clrscr();
   s=(stack*)malloc(sizeof(stack));
   printf("\n creat a stack::");
   printf("\n enter the no of elemet::");
   scanf("%d",&num);
   printf("\n enter the element::");
   scanf("%d",&s->info);
    s->link='\0';
    display(s);
   for(i=1;i<num;i++)
    {
     new=(stack*)malloc(sizeof(stack));
      printf("\n enter the element::");
      scanf("%d",&new->info);
      new->link=s;
      s=new;
      display(s);
      }


  do
   {

    printf("\n ***********MENU*********\n");
    printf("\n1.Push in the stack.\n");
    printf("\n2.Pop from the stack.\n");
    printf("\n3.Print top element.\n");
    printf("\n4.Duplicate top element.\n");
    printf("\n5.Swap top two element.\n");
    printf("\n6.Clear the stack.\n");
    printf("\n7.EXIT\n");
    printf("\nEnter your choice:(1/2/3.....)::");
    scanf("%d",&i);
     switch(i)
     {
     case 1:printf("\n how many element u want to push::");
	    scanf("%d",&n);
	    for(i=1;i<=n;i++)
	    {
	    s=push(s,1);
	    display(s);
	    }
	    break;
     case 2:while(yes_no=='y')
	      {
		printf("\nThe poped element is::%d",s->info);
		s=s->link;
		display(s);
		if(s==NULL)
		 printf("\n The stack is empty::UNDERFLOW");
		printf("\nwant to pop more(y/n)::");
		yes_no=getche();
		}
		break;
    case 3:  clrscr();
	     display(s);
	     printtop(s);
	     break;

    case 4: clrscr();
	    s=duplicate(s);
	    display(s);
	    break;

    case 5:  clrscr();
	     s=swaptoptwo(s);
	     display(s);
	     break;

    case 7:
	      flag=0;
	      break;
	 default:
	       printf("\n you have entered wrong choice try again::");
	 }
       }while(flag);
       getch();
    }

