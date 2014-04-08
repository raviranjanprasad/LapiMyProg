                     
                     /*LINK LIST PROGRAM TRAVERSE WITH SUBSTRACTION*/

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

 /*FUNCTION TO TRAVERSE A LINK LIST*/
     node *traverse(node *head)
     {
      node *ptr,*sub1,*sub2,*res;

       sub1=head;
      sub2=sub1->next;
      ptr=sub2;
      res=(node*)malloc(sizeof(node));
       res->number=(sub2->number)-(sub1->number);
       res->next=sub1;
       	head=res;
	sub1=sub2->next;
	sub2=sub1->next;
       while(sub2!='\0')
       {
       res=(node*)malloc(sizeof(node));
       res->number=(sub1->number)-(sub2->number);
       res->next=sub1;
       ptr->next=res;
       ptr=sub2;
       sub1=sub2->next;
       sub2=sub1->next;
       }

      return(head);
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
      printf("\n 3.Traverse with substraction.");
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
	       head=traverse(head);
	       display(head);
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