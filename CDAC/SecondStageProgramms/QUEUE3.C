	     /*PROGRAM TO IMPLEMENT THE QUEUE BY LINK LIST*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
/*#define MAX 6;*/
typedef struct node
{
 int info;
 struct node *next;
 }node;
/* node *front=NULL,*rear=NULL;*/


/*FUNCTION TO DISPLAY*/
 void display(node *front)
  {
    node *ptr;
    ptr=front;
    printf("\n front-->");
    while(ptr!='\0')
    {
     printf("%d-->",ptr->info);
     ptr=ptr->next;
     }
     printf("rear");
   }

/*FUNCTION TO ENQUEUE*/
   node *enqueue(node *front,node *rear,int item)
    {
     node *new,*ptr;
     ptr=front;
     new=(node*)malloc(sizeof(node));
     new->next=NULL;
     new->info=item;

     /*check for empty queue*/
     if(front==NULL)
      {
      front=new;
      rear=new;
      }
      else
      {
	  while(ptr->next!=NULL)
	    {
	     ptr=ptr->next;
	     rear=rear->next;
	      }
	 ptr->next=new;
	 rear->next=new;
	 rear=rear->next;
       }
       return(front);

      /* display(front);*/
     }


/*FUNCTION TO DEQUEUE*/
  node *del_queue(node *front)
   {
    node *temp;
    if(front!=NULL)
    {
     temp=front;
     front=front->next;
     free(temp);
     }
   /*else if(front==NULL)
     {
     printf("\n UNDERFLOW....the queue is empty::");
     break;
     }*/
      return(front);

   }



 /* MAIN FUNCTION */
  void main()
  {
    node *front,*rear;
    int i,choice,flag=0,item;
    clrscr();
    front=NULL;
    rear=NULL;
    do
     {
      printf("\n---------------");
      printf("\nMENU FOR QUEUE");
      printf("\n---------------");
      printf("\n 1.Insert");
      printf("\n 2.Delete");
      printf("\n 3.EXIT");
      printf("\n Enter your choice::");
      scanf("%d",&choice);
      switch(choice)
       {
       case 1:  printf("\n Enter the new element::");
		 scanf("%d",&item);
		front=enqueue(front,rear,item);
		display(front);
		 break;
	case 2:
		front=del_queue(front);
		if(front==NULL)
		 printf("\n UNDERFLOW..... The queue is empty.");
		 display(front);
		break;
	case 3:
		flag=1;
		break;
	default:
		   printf("\n wrong choice");
	    }
	  /*  printf("\n The queue is::");
	    display(front);*/
	   /* if(front==NULL)
	     printf("\n The queue is Empty");*/
	  }while(!flag);
	 getch();
	}










