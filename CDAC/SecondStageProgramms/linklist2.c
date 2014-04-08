                          
                     /* LINK LIST PROGRAM FOR THE ATTACHEMENT AND DEATTACHMENT*/

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

/* FUNCTION TO ATTACH AND DEATTACH A NODE*/
   void attachdeattach(node *head)
   {
    int n,i;
    node *avail,*ptr,*save;
    printf("\n enter the position to detach the node::");
    scanf("%d",&n);
    ptr=head;
    avail=(node*)malloc(sizeof(node));
    for(i=1;i<n;i++)
    {
      save=ptr;
      ptr=ptr->next;
      }
      save->next=ptr->next;
      ptr->next=avail;
      avail=ptr;
      printf("\n link list after detach::\n");
      display(head);
      printf("\n enter the no of node at which this detched node is to be attached::");
      scanf("%d",&n);
      ptr=head;
      for(i=1;i<n-1;i++)
       ptr=ptr->next;
      avail->next=ptr->next;
      ptr->next=avail;
      printf("\n Link list after attachement::\n");
      display(head);
      }

   /* MAIN FUNCTION */
    void main()
    {
     node *head;
     int n,i,flag=1;
     clrscr();
     printf("\n\t\t/*LINK LIST MENU*/\n");
     do
     {

      printf("\n 1.Create a link list.");
      printf("\n 2.Display a link list.");
      printf("\n 3.Deattached and Attached.");
      printf("\n 4.EXIT");
      printf("\n Enter your choice::");
      scanf("%d",&i);
      switch(i)
      {
       case 1:
	       printf("\n Enter the no of nodes::");
	       scanf("%d",&n);
	       head=(node*)malloc(sizeof(node));
	       printf("\n enter the no::");
	       scanf("%d",&head->number);
	       head=create(head,n);
	       display(head);
	       break;

       case 2:
	       display(head);
	       break;

      case 3:
	       attachdeattach(head);
	       break;

      case 4:
		 flag=0;
		 break;
     default:
	       printf("\n you have entered wrong choice try again");
	    }
	  }while(flag);
     getch();
     }

