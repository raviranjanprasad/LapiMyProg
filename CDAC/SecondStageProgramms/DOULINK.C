	                  /*PROGRAM FOR THE DOUBLY LINK LIST */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

/*STRUCTURE OF A NODE HAVING FORWARD LINK AND BACKWARD LINK AND AND INT INFO*/
typedef struct node
{
 struct node *prev;
 int info;
 struct node *next;
 }node;
 node *head=NULL,*tail=NULL;  /*GLOBAL VARIABLE HEAD AND TAIL OF THE LINK LIST*/
 node *ptr;

/*FUNCTION TO CREATE A  DOUBLY LINK LIST*/
  void create()
  {
    int i,n;
    node *new,*ptr;
    clrscr();
    ptr=(node*)malloc(sizeof(node));
    printf("\n Enter the no of nodes::");
    scanf("%d",&n);
    printf("\n Enter an element::");
    scanf("%d",&ptr->info);
    head=ptr;
    tail=ptr;
     for(i=1;i<n;i++)
     {
       new=(node*)malloc(sizeof(node));
       printf("\n Enter an element::");
       scanf("%d",&new->info);
       new->next=NULL;
       new->prev=tail;
       tail->next=new;
       tail=new;
       }
       ptr=NULL;
     }


  /*FUNCTION TO DISPALY THE DOUBY LINK LIST IN FORWARD DIRECTION*/
 void display(node *head)
  {
   node *ptr1;

   printf("\n forward direction::");
   printf("\nHEAD");
   ptr1=head;
   while(ptr1!='\0')
    {
     printf("<-->%d",ptr1->info);
     ptr1=ptr1->next;
     }
     printf("<-->TAIL");
   }


 /*FUNCTION TO DISPLAY THE LIST IN REVERSE DIRECTION*/
  void display_in_reverse(node *tail)
  {
   node *ptr2;
   ptr2=tail;
     printf("\n");
     printf("\n Backward direction::");
     printf("\nTAIL");
     while(ptr2!='\0')
     {
      printf("<-->%d",ptr2->info);
      ptr2=ptr2->prev;
      }
      printf("<-->HEAD");
    }



/*FUNCTION TO INSERT A ELEMENT AT THE BEGINING*/
  void insert_at_beginning()
    {
   node *new;
   clrscr();
   new=(node*)malloc(sizeof(node));
   printf("\n Enter an element::");
   scanf("%d",&new->info);
   if(head==NULL)
   {
    new->next=NULL;
    new->prev=NULL;
    head=tail=new;
    }
  else
    {
   new->prev=NULL;
   new->next=head;
   head->prev=new;
   head=new;
      }
     }

 /*FUNCTION TO INSERT AT THE END*/
  void insert_at_the_end()
   {
    node *new;
    new=(node*)malloc(sizeof(node));
     printf("\n Enter an element::");
     scanf("%d",&new->info);
     if(head==NULL)
      {
       new->prev=NULL;
       new->next=NULL;
       head=tail=new;
       }
      else
      {
       new->next=NULL;
       new->prev=tail;
       tail->next=new;
       tail=new;
       }
      }

/*FUNCTION TO SEARCH THE LOCATION OF A  ELEMENT*/
  node *search(node *head,int item)
   {
    node *loc;
    int flag=0;
    loc=head;
    while(loc!=NULL)
     {
       if(loc->info==item)
       {
	flag=1;
	return(loc);
	}
	loc=loc->next;
	}
      if(!flag)
       return(NULL);
    }

/*FUNCTION TO INSERT AN ELEMENT AFTEER A GIVEN ELEMENT*/
  void insert_after()
   {
     node *new,*loc;
     int element;
     printf("\n Enter an element after which item is to be inserted::");
     scanf("%d",&element);
     new=(node*)malloc(sizeof(node));
     loc=search(head,element);
     if(loc==NULL)
     {
     printf("\n There is no such item::");
     return;
     }
     printf("\n Enter an element::");
     scanf("%d",&new->info);
     if(loc->next==NULL)
      {
       new->next=NULL;
       new->prev=tail;
       tail->next=new;
       tail=new;
       }
       else
       {
       new->next=loc->next;
       new->prev=loc;
       loc->next->prev=new;
       loc->next=new;
       }
       clrscr();
     }


/* FUNCTION TO INSERT BEFORE A GIVEN ELEMENT*/
   void insert_before()
    {
     node *new,*loc;
     int element;
     printf("\n Enter an element before which item is to be inserted::");
     scanf("%d",&element);
     new=(node*)malloc(sizeof(node));
     loc=search(head,element);
     if(loc==NULL)
     {
     printf("\n There is no such item::");
     return;
     }
     printf("\n Enter an element::");
     scanf("%d",&new->info);
     if(loc->prev==NULL)
      {
       new->next=head;
       new->prev=NULL;
       loc->prev=new;
       head=new;
       }
       else
       {
	new->next=loc;
	new->prev=loc->prev;
	loc->prev->next=new;
	loc->prev=new;
	}
       clrscr();
       }


/*FUNCTION TO DELETE AT THE START*/
  void delete_at_beginning()
  {
    if(head==NULL)
    return;
    else
     {
     head=head->next;
     head->prev=NULL;
     }
  }

/*FUNCTION TO DELETE AT THE END*/
 void delete_at_end()
  {
    if(head==NULL)
      return;
      else
       {
	 tail=tail->prev;
	 tail->next=NULL;
	 }
     }


/*FUNCTION TO DELETE BEFORE A GIVEN ELEMENT*/
 void delete_before_a_given_element()
  {
   node *loc,*ptr;
   int element;
   ptr=head;
   printf("\nEnter the element after which the element is to be deleted::");
   scanf("%d",&element);
    loc=search(head,element);
   if(loc==NULL)
    {
     printf("There is no such element\n");
     return;
     }
     else if(loc->next->next==NULL)
     {
      ptr=loc->next;
      loc->next=NULL;
      tail=loc;
      free(ptr);
      }
      else
      {
	ptr=loc->next;
	loc->next=ptr->next;
	ptr->next->prev=loc;
	 free(ptr);
       }
    }
/* FUNCTION TO DELETE AFTER AN ELEMENT*/
   void delete_after_a_given_element()
   {
    node *ptr,*loc;
    int element;
   ptr=head;
   printf("\nEnter the element after which the element is to be deleted::");
   scanf("%d",&element);
    loc=search(head,element);
   if(loc==NULL)
    {
     printf("There is no such element\n");
     return;
     }
     else if(loc->prev->prev==NULL)
     {
      ptr=loc->prev;
      loc->prev=NULL;
      head=loc;
      free(ptr);
      }
      else
      {
	ptr=loc->prev;
	loc->prev=ptr->prev;
	ptr->prev->next=loc;
	 free(ptr);
       }
    }


/*MAIN FUNCTION*/
 void main()
 {
  int choice,element,before,after;
  int flag=0;
  clrscr();
  do
  {
   printf("\n1.Create the doubly linklist");
   printf("\n2.Insert at the begining");
   printf("\n3.Insert at the end");
   printf("\n4.Insert after a given element");
   printf("\n5.Insert before a given element");
   printf("\n6.Traverse inorder.");
   printf("\n7.Traverse in reverse order.");
   printf("\n8.Delete at the beginning");
   printf("\n9.Delete at the end");
   printf("\n10.Delete before a given element");
   printf("\n11.Delete after a given element");
   printf("\n12.EXIT.");
   printf("\n ENTER YOUR CHOICE::(1-12):");
   scanf("%d",&choice);
   switch(choice)
    {
      case 1:  create();
	       display(head);
	       display_in_reverse(tail);
	       break;

     case 2: insert_at_beginning();
	     display(head);
	     display_in_reverse(tail);
	      break;
      case 3:
	      insert_at_the_end();
	      display(head);
	      display_in_reverse(tail);
	      break;
      case 4:
		insert_after();
		display(head);
		display_in_reverse(tail);
		break;
       case 5:
		insert_before();
		display(head);
		display_in_reverse(tail);
		break;
      case 6:
	       display(head);
	       break;
      case 7:
	       display(tail);
	       break;
      case 8:
	       delete_at_beginning();
	       display(head);
	       display_in_reverse(tail);
	       break;
       case 9:
	       delete_at_end();
	       display(head);
	       display_in_reverse(tail);
	       break;
       case 10:
	       delete_before_a_given_element();
	       display(head);
	       display_in_reverse(tail);
	       break;
      case 11:
	       delete_after_a_given_element();
	       display(head);
	       display_in_reverse(tail);
	       break;
      case 12:
	       flag=1;
	       break;
       default:
	       printf("\n Wrong choice TRY AGAIN::");
	 }
     }while(!flag);
   }




