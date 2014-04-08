
                   /*PROGRAM TO DETAILS OF EMPLOYEE RECORD AND UPDATE IT*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
/*STRUCTURE OF EMPLOYEE*/
typedef struct employee
{
 char name[30];
 long int empno;
 char desig[30];
 long  int bapay;
 long   int teleno;
 char dept[30];
 struct employee *next;
  }employee;
  /*FUNCTION TO CREATE A LINK LIST OF EMPLOYEE*/
   employee *create(employee *first,int n)
    {
      int i;
      employee *new,*temp;
      temp=first;
      for(i=1;i<=n-1;i++)
      {
	new=(employee*)malloc(sizeof(employee));
	printf("\n enter employee name::");
	scanf("%s",new->name);
	printf("\n enter employee Id no::");
	scanf("%ld",&new->empno);
	printf("\n enter Designation::");
	scanf("%s",new->desig);
	printf("\n enter Basic pay::");
	scanf("%ld",&new->bapay);
	printf("\n enter telephone no::");
	scanf("%ld",&new->teleno);
	printf("\n enter depatrment::");
	scanf("%s",new->dept);
	new->next='\0';
	temp->next=new;
	temp=new;
      }
	 temp='\0';
	 return first;
   }
   /*DISPLAY FUNCTION*/
       void display(employee *first)
       {
	employee *temp;
	temp=first;
	printf("\n the employee list is::\n");
	printf("--------------------------------------------------------------\n");
	printf(" EMPE_NO       NAME      DESIG    B_PAY      TELE_NO        DEP\n");
	printf("---------------------------------------------------------------\n");
	while(temp!='\0')
	 {
	   printf("%8ld",temp->empno);
	   printf("%10s",temp->name);
	   printf("%12s",temp->desig);
	   printf("%12ld",temp->bapay);
	   printf("%12ld",temp->teleno);
	   printf("%12s",temp->dept);
	   temp=temp->next;
	   printf("\n");
	  }

	}
 /* ADD NAMES */
 void *add(employee *first)
   {
   employee *new,*temp;
   char name1[30];
   int flag=0;
   new=(employee*)malloc(sizeof(employee));
   printf("\n enter employee name::");
	scanf("%s",new->name);
	printf("\n enter employee Id no::");
	scanf("%ld",&new->empno);
	printf("\n enter Designation::");
	scanf("%s",new->desig);
	printf("\n enter Basic pay::");
	scanf("%ld",&new->bapay);
	printf("\n enter telephone no::");
	scanf("%ld",&new->teleno);
	printf("\n enter depatrment::");
	scanf("%s",new->dept);
	 printf("\nenter the name of employee after which record is to be inserted::");
	 scanf("%s",name1);
	 temp=first;
       while(temp!='\0')
       {
	 if((strcmp(temp->name,name1)==0))
	  {
	   flag=1;
	   break;
	   }
	 else
	 temp=temp->next;
	 }
      if(flag)
      {
      new->next=temp->next;
      temp->next=new;
      }
      else if(!flag)
	printf("\n The name is not in the list\n");
      temp='\0';
      display(first);
    }

    /* ADD ANOTHER EMPLOYEE*/
    void insert(employee *first)
    {
     employee *new,*temp;
     new=(employee*)malloc(sizeof(employee));
	printf("\n enter employee name::");
	scanf("%s",new->name);
	printf("\n enter employee Id no::");
	scanf("%ld",&new->empno);
	printf("\n enter Designation::");
	scanf("%s",new->desig);
	printf("\n enter Basic pay::");
	scanf("%ld",&new->bapay);
	printf("\n enter telephone no::");
	scanf("%ld",&new->teleno);
	printf("\n enter depatrment::");
	scanf("%s",new->dept);
	new->next='\0';
	temp=first;
	while(temp->next!='\0')
	 temp=temp->next;
	 temp->next=new;
	 display(first);
	 }

/*DETAILS OF EMPLOYEE DEPARTMENT WISEE*/
    void detailsdep(employee *first)
    {
     employee *temp;
     char depart[30];
     temp=first;
     printf("\n Enter the name of department::");
     scanf("%s",depart);
     temp=first;
	printf("\n the employee list is::\n");
	printf("--------------------------------------------------------------\n");
	printf(" EMPE_NO       NAME      DESIG    B_PAY      TELE_NO        DEP\n");
	printf("---------------------------------------------------------------\n");

     while(temp!='\0')
     {
     if((strcmp(temp->dept,depart))==0)
      {
	   printf("%8ld",temp->empno);
	   printf("%10s",temp->name);
	   printf("%12s",temp->desig);
	   printf("%12ld",temp->bapay);
	   printf("%12ld",temp->teleno);
	   printf("%12s",temp->dept);
	   printf("\n");
	  }
	  temp=temp->next;
	}
      }

   /* DETAILS OF EMPLOYEE*/
   void detailsemp(employee *first)
   {
     employee *temp;
     char name2[30];
     int flag=0;
     temp=first;
     printf("\n Enter the name of the employee::");
     scanf("%s",name2);
     temp=first;
	printf("\n the employee list is::\n");
	printf("--------------------------------------------------------------\n");
	printf(" EMPE_NO       NAME      DESIG    B_PAY      TELE_NO        DEP\n");
	printf("---------------------------------------------------------------\n");

     while(temp!='\0')
     {
     if((strcmp(temp->name,name2))==0)
      {
	   printf("%8ld",temp->empno);
	   printf("%10s",temp->name);
	   printf("%12s",temp->desig);
	   printf("%12ld",temp->bapay);
	   printf("%12ld",temp->teleno);
	   printf("%12s",temp->dept);
	   printf("\n");
	   flag=1;
	  }
	  temp=temp->next;
	}
	if(!flag)
	  printf("The name is not in the list::");
     }

/* FUNCTION TO FIND OUT THE TELEPHONE NO OF A EMPLOYEE*/
 void telephoneno(employee *first)
  {

     employee *temp;
     char name2[30];
     int flag=1;
     temp=first;
     printf("\n Enter the name of the employee::");
     scanf("%s",name2);
     temp=first;
     while(temp!='\0')
     {
     if((strcmp(temp->name,name2))==0)
     {
       printf("%12ld",temp->teleno);
       flag=0;
       break;
       }
	temp=temp->next;
	}
	if(flag)
	 printf("\n The name is not in the list::");
     }

 /* MAIN FUNCTION*/
 void main()
 {
  int n,ch,flag=1;
  char name1[30];
   employee *first,*list,*new1;
  clrscr();
  printf("\enter the no of employee to be added::");
  scanf("%d",&n);
  if(n>=1)
  {
  first=(employee*)malloc(sizeof(employee));
  printf("\n enter employee name::");
  scanf("%s",first->name);
  printf("\n enter employee id::");
  scanf("%ld",&first->empno);
  printf("\n enter Designation::");
  scanf("%s",first->desig);
  printf("\n enter basic pay::");
  scanf("%ld",&first->bapay);
  printf("\n enter telephone no::");
  scanf("%ld",&first->teleno);
  printf("\n enter the department::");
  scanf("%s",first->dept);
  first->next='\0';
  }
  list=create(first, n);
  clrscr();
  display(list);

  do
   {
   printf("\n\n");
   printf("\n*******MENU*******\n");
   printf("\n1.Add another employee after a given name\n");
   printf("\n2.Add another employee record\n");
   printf("\n3.Details of employee department wise\n");
   printf("\n4.Edit data of an employee by name\n");
   printf("\n5.Find out the telephone no of an employee\n");
   printf("\n6.EXIT\n");
  printf("\n enter your choice::");
  scanf("%d",&ch);
  switch(ch)
   {
     case 1:  add(first);
	      break;
     case 2:
	     insert(first);
	     break;
     case 3:
	     detailsdep(first);
	     break;
     case 4:
	     detailsemp(first);
	     break;
     case 5:
	      telephoneno(first);
	       break;
       case 6:
	       flag=0;
	       break;
      default:
		 printf("\n You have done wrong entry try again::");
		 break;
	   }
	 }while(flag);
    getch();
    }

