                     
                     /*LINK LIST PROGRAM TRAVERSE WITH SUBSTRACTION*/

#include<iostream>

using namespace std;

typedef struct node
{
 int number;
 struct node *next;
}node;

  /*FUNCTION TO CREATE A LINK LIST*/
 node *create(node *head,int n)
 {
  int i;
  node *tnew,*ptr;
  ptr=head;
  for(i=1;i<n;i++)
   {
     tnew=(node*)malloc(sizeof(node));
     printf("\nenter the number::");
     scanf("%d",&tnew->number);
     ptr->next=tnew;
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
   node *ReverseLinkList(node *head)
   {
	   node *ptr,*temp,*stemp;

	   ptr = head;
	   temp = ptr->next;
	   stemp = temp->next;

	   while (1)
	   {
		   if(temp->next == '\0')
		   {
			   temp->next= ptr;
			   head = temp;
			   return(head);
		   }
		   else
		   {
			   temp->next = ptr;
			   
		   }

		   if(ptr == head)
		   {
			   ptr->next = '\0';
			   ptr = temp;
			   temp = stemp;
			   stemp = stemp->next;
		   }   
		   else
		   {
			   ptr = temp;
			   temp = stemp;
			   stemp = stemp->next;

		   }
	   }

	   

   }
     
    /* MAIN FUNCTION */
    void main()
    {
     node *head;
     int n,i,flag=1;
  
     printf("\n\t\t/*LINK LIST MENU*/\n");
     do
     {

      printf("\n 1.Create a link list.");
      printf("\n 2.Display a link list.");
      printf("\n 3.Reverse the link List.");
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
		     
	       //head=traverse(head);
		   head = ReverseLinkList(head);
	       display(head);
	       break;

      case 4:
		 flag=0;
		 break;
     default:
	       printf("\n you have entered wrong choice try again");
	    }
	  }while(flag);

     }
