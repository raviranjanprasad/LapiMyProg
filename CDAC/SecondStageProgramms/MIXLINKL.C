
						/*LINK LIST PROGRAM FOR TEH INSERTION */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct node
{
 int number;
 struct node *next;
  }node;

  /*FUNCTION TO CREATE A LINK LIST*/
 node *create(node *head,int n)
 {
  int i;
  node *new,*ptr;
  ptr=head;
  for(i=1;i<n;i++)
   {
     new=(node*)malloc(sizeof(node));
     printf("\nenter the number::");
     scanf("%d",&new->number);
     ptr->next=new;
     ptr=ptr->next;
     ptr->next='\0';
    }
     return(head);
   }

   /* FUNCTION TO DISPALY A LINK LIST*/
   void display(node *head)
   {
    node *ptr;
    ptr=head;
    while(ptr!='\0')
     {
       printf("-->%d",ptr->number);
	ptr=ptr->next;
      }
     }

  /*FUNCTION TO INSERT A NODE IN THE LINK LIST*/
  node *Insert_at_the_start(node *head)
  {
   node *new;
   new=(node*)malloc(sizeof(node));
   printf("\n enter the number::");
   scanf("%d",&new->number);
   new->next=head;
   head=new;
   return(head);
   }


   /*FUNCTION TO INSERT AFTER A GIVEN NODE*/
   node *Insert_after_a_given_node(node *head)
   {
   int n,i;
   node *ptr,*new;
    ptr=head;
    printf("\n Enter the node after which you want to insert::");
    scanf("%d",&n);
     new=(node*)malloc(sizeof(node));
     printf("\n Enter a number::");
     scanf("%d",&new->number);
    for(i=1;i<n;i++)
    ptr=ptr->next;
    new->next=ptr->next;
    ptr->next=new;
    return(head);
    }

    /* FUNCTION TO ISERT THE NODE AT THE END OF THE LINK LIST*/
    node *Insert_at_the_end(node *head)
    {
     node *ptr,*new;
     new=(node*)malloc(sizeof(node));
     printf("\n Enter a number::");
     scanf("%d",&new->number);
     ptr=head;
     while(ptr->next!='\0')
      ptr=ptr->next;
      ptr->next=new;
      new->next='\0';
      return(head);
      }



 /*MAIN  FUNCTION*/
 void main()
 {
  node *head;
  int n,num,flag=1;
  clrscr();
  head=(node*)malloc(sizeof(node));

	 printf("\n\t\t\t*MENU FOR THE LINK LIST*\n");
  do
    {
      printf("\n1.Create a link list.\n");
      printf("\n2.Insert a node at the begining.\n");
      printf("\n3.Insert the node after a particular position\n");
      printf("\n4.Insert a node at the end.\n");
      printf("\n5.EXIT\n");
      printf("\n Enter your choice::");
      scanf("%d",&num);
      switch(num)
       {
	 case 1:

		 printf("enter the number of the node");
		 scanf("%d",&n);
		 printf("\n enter the number::");
		 scanf("%d",&head->number);
		 head->next='\0';
		 head=create(head,n);
		 display(head);
		 break;
	  case 2:
		 head=Insert_at_the_start(head);
		 display(head);
		 break;

	    case 3:
		  head=Insert_after_a_given_node(head);
		  display(head);
		  break;
	    case 4:
		  head=Insert_at_the_end(head);
		  display(head);
		  break;
	     case 5:
		     flag=0;
		     break;
	     default:
		     printf("\n wrong choice enter again::");
	       }

	      }while(flag);
   getch();
  }

