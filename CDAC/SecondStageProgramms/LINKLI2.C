
			 /* LINK LIST PROGRAM TO PICK ALL ODD NUMBER OF NODES AND PLACE THEM IN THE
                                       BEGINNING OF THE LIST */

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

/* FUNCTION TO PICK ALL ODD NUMBER OF NODES AND PLACE THEM
        IN THE BEGINNING OF THE LIST*/
	node *pickodd(node *head)
    {
     node *avail,*ptr,*save,*temp,*odd,*head1;
     ptr=head;
/*     avail=(node*)malloc(sizeof(node));*/
     head=ptr->next;
     avail=ptr;
     temp=avail;
     ptr=head;
     save=ptr;
      while(save!='\0')
      {
	ptr=save->next;
	save->next=ptr->next;
	temp->next=ptr;
	temp=temp->next;
	save=save->next;
       }
       temp->next='\0';
       odd=(node*)malloc(sizeof(node));
	head1=odd;
      while(avail!='\0')
      {
       odd->number=avail->number;
       avail=avail->next;
       odd->next=(node*)malloc(sizeof(node));
       odd=odd->next;
       }
       while(head!='\0')
       {
       odd->number=head->number;
       head=head->next;
       odd->next=(node*)malloc(sizeof(node));
       odd=odd->next;
       }
       odd->next='\0';
       return(head1);
    }


/*MAIN FUNCTION */
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
      printf("\n 3.Picd all the odd numbered nodes and place themin the beginning.");    printf("\n 4.EXIT");
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
	       head=pickodd(head);
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