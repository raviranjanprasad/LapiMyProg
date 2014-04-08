#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
  char name[15];
  struct node *next;
 }node;
 node *create(node *head)
 {
   char name1[15],ch;
   int i=0,wcount=0;
   node *temp,*prev;
   FILE *fp;
   prev=head=NULL;
   if((fp=fopen("linword.txt","r"))==NULL)
     {
       printf("\n Unable to open the file linword.txt");
       exit(1);
      }
     while((ch=fgetc(fp))!=EOF)
      {
	if(ch!='\n')
	 {
	   name1[i]=ch;
	   i++;
	 }
	 else if(ch=='\n')
	  {
	   name1[i]='\0';
	   wcount++;

	      temp=(node*)malloc(sizeof(node));
	      strcpy(temp->name,name1);
	      temp->next=NULL;

		 if(head==NULL)
		     head=temp;
		 else
		     prev->next=temp;

		     prev=temp;
		 i=0;
	  }
	}
	   if(ch==EOF)
	   name1[i]='\0';
           temp=(node*)malloc(sizeof(node));
	      strcpy(temp->name,name1);
	      temp->next=NULL;
      printf("\n The number of word in the file are::%d",wcount);
      fclose(fp);
      return(head);
   }
     void display(node*head)
     {
      node *temp;
      for(temp=head;temp!=NULL;temp=temp->next)
	 printf("%s-->",temp->name);
      return;
     }
     void main()
     {
	node *head;
	clrscr();
	head=create(head);
	printf("\n the created linked list is::\n");
	display(head);
	getch();
     }
