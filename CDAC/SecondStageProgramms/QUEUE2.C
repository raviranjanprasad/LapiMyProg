		/*PROGRAM TO IMPLEMENT THE CIRCULAR QUEUE WITH ARRAY*/

#include<stdio.h>
#include<conio.h>
#define NIL -1
#define MAX 6
typedef struct
 {
  int front;
  int rear;
  int elements[MAX];
  }queue_type;

/*FUNCTION TO CREATE AN QUEUE*/
 queue_type *create_queue(queue_type *queue)
  {
   queue->front=queue->rear=NIL;
   return(queue);
   }

/* IS QUEUE EMPTY*/
 int isempty(queue_type *queue)
  {
    if(queue->front==NIL)
     return 1;
     else
      return 0;
    }

 /*IS QUEUE FULL*/
  int isfull(queue_type *queue)
  {
   if((queue->front==0)&&(queue->rear==(MAX-1))||(queue->front==queue->rear+1))
     return 1;
     else
      return 0;
    }

 /*DISPLAY FUNCTION*/
  void display(queue_type *queue)
   {
    int i=0;
    printf("QUEUE-->");
    for(i=queue->front;i<=queue->rear;i++)
      printf("| %d|",queue->elements[i]);
      }


  /* FUNCTION TO INSERT INTO THE QUEUE*/
  void enqueue(queue_type *queue,int x)
   {
    int i;
    if(queue->front==NIL)
    {
     queue->front=queue->rear=0;
      printf("\nfront::%d",queue->front);
      printf("\nrear::%d",queue->rear);
      queue->elements[queue->rear]=x;
       }

     else if(queue->rear==(MAX-1))
     {
       queue->rear=0;
         printf("\nfront::%d",queue->front);
      printf("\nrear::%d",queue->rear);

       }
       else
	 {
	  queue->rear++;
	  printf("\nfront::%d",queue->front);
	  printf("\nrear::%d",queue->rear);
	  queue->elements[queue->rear]=x;

	  }
       display(queue);
      }

/* FUNCTION TO DELETE A ELEMENT QUEUE*/
       int dequeue(queue_type *queue)
       {
	 int temp;
	 temp=queue->elements[queue->front];
	 if(queue->front==queue->rear)
	 {
	   queue->front=queue->rear=NIL;
            printf("\nfront::%d",queue->front);
	  printf("\nrear::%d",queue->rear);
	  }
	   else if(queue->front==(MAX-1))
	   {
	     queue->front=0;
	     printf("\nfront::%d",queue->front);
	     printf("\nrear::%d",queue->rear);
	  }
	   else
	    {
	    queue->front++;
	    printf("\nfront::%d",queue->front);
	    printf("\nrear::%d",queue->rear);
	     }
	    return temp;
	 }


/*MAIN FUNCTION*/
void main()
 {
  int choice,n,x,flag=1,k;
  queue_type *queue;
  clrscr();
  queue=(queue_type*)malloc(sizeof(queue_type));
  queue->front=0;
  queue->rear=NIL;
  queue=create_queue(queue);

  do
    {
     printf("\n\t\t*IMPLEMENTATION OF QUEUE WITH THE HELP OF ARRAY*");
     printf("\n*******************");
     printf("\n *MENU FOR QUEUE*");
     printf("\n********************");
     printf("\n 1.Enqueue");
     printf("\n 2.Dequeue");
     printf("\n 3.Exit");
     printf("\n\nENTER your choice::");
     scanf("%d",&choice);
     switch(choice)
      {
       case 1: clrscr();

		 if(isfull(queue))
	       {
	       printf("queue full..\n\npress any key to continue");
	       getch();
	       break;
	       }
	       else
	       {
		printf("Enter value:");
		scanf("%d",&x);
		enqueue(queue,x);
		}
		break;

      case 2:  clrscr();
	       if(isempty(queue))
	       {
		printf("\n Queue Empty...\n\npress any key to continue.");
		getch();
		}
		else
		{
		k=dequeue(queue);
		printf("\n The value dequed is:: %d",k);
		printf("\n press any key to continue::");
		getch();
		}
		display(queue);
		break;
	case 3:
		flag=0;
		break;
	 default:
		 printf("You have entered wrong choice");
	    }
	   }while(flag);
	 getch();
       }









