	   /*PROGRAM TO FIND THE NO OF OCCURANCE OF
	     A PARTICULR STRING IN A MAINSTRING*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

/*FUNCTION TO FIND THE OCCURANCE OF A SUBSTRING*/
   int find_no_of_occurance(char mainstr[],char patstr[])
   {
     int i,j,len1,len2,flag=0,count=0;
     len1=strlen(mainstr);
     len2=strlen(patstr);
     j=0;
     for(i=0;i<=len1;i++)
     {
	 if(mainstr[i]!=patstr[j])
	    flag=1;
	    else
	    {
	      flag=0;
	      j++;
	      }
	   if((flag==0)&&(j==len2))
	   {
	     count++;
	     j=0;
	     }
	 }
	 return(count);
      }




/*MAIN FUNCTION*/
void main()
{
 char mainstr[150],patstr[10];
 int n;
 clrscr();
 printf("\n Enter the main string::");
 gets(mainstr);
 printf("\n Enter the substring::");
 gets(patstr);
 n=find_no_of_occurance(mainstr,patstr);
 printf("The no of occurance of substirng in main string is %d",n);
 getch();
 }
