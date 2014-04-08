                
						 /*PROGRAM FOR TOWER OF HANOI*/

#include<stdio.h>
#include<conio.h>
/* FUUCTION TO SHIFT THE DISK*/
  void hanoi(int n,char dl,char dc,char dr)
   {
    if(n!=0)
     {
       /*Move n-1 disk from starting needle to intermediate needle*/
	hanoi(n-1,dl,dr,dc);
	/*Move disk n form start to destination*/
	printf("Move disk %d from %c to %c\n",n,dl,dr);
	/*Move n-1 disk form intermediate needle to destinastion needle*/
	hanoi(n-1,dc,dl,dr);
	}
     }

/* FUNCTION MAIN*/
void main()
{
 int nvalue;
 char left='L',center='C',right='R';
 clrscr();
 printf("\nEnter the number of nodes::");
 scanf("%d",&nvalue);
 printf("\n\n Tower of Honey with %d disk\n",nvalue);
 hanoi(nvalue,left,center,right);
 printf("\n");
 getch();
 }
