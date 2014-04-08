                    /*PROGRAM TO PRINT THE NAME AND AVERAGE OF THE PLAYERS OF
					              DIFFERENT CRICKET TEAMS*/

#include<stdio.h>
#include<conio.h>
typedef struct
 {
 char name[30];
 int avg;
 }player;
 typedef struct
 {
 char tnm[30];
 player p[12];
 }cricket;
 /* DATA ENTRY FUNCTION*/
 dataentry(cricket team[],int n)
 {
 int j;
 clrscr();
 printf("\n enter the names of player of %s team with their batting avg:",team[n].tnm);
 for(j=0;j<3;j++)
 {
 printf("\n enter the name:");
 scanf("%s",team[n].p[j].name);
 printf("\n batting avg:");
 scanf("%d",&team[n].p[j].avg);
  }
  return 0;
  }

/* LIST DISPLAY*/
void listdisplay(cricket team[],int n)
{
int k,l;
clrscr();
for(k=0;k<n;k++)
{
l=k+1;
printf("\n%d. %s",l,team[k].tnm);
 }
 }
 /* DISPLAY FUCTION*/
 void display(cricket team[],int n)
 {
 int j;
 clrscr();
 printf("country name %s:\n", team[n].tnm);
 printf("  NAME                           AVERAGE\n");
 for(j=0;j<3;j++)
 {
     printf("\n%10s",team[n].p[j].name);
     printf("                      ");
     printf("%3d",team[n].p[j].avg);
     }
     }

 /*MAIN FUNCTION*/
 void main()
 {
 int i,n,num,s1=0;
 cricket team[10];
 clrscr();
 printf("\n enter the number of teams: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 clrscr();
 s1=s1+1;
 printf("\n enter the name of %d team:",s1);
 scanf( "%s",team[i].tnm);
 dataentry(team,i);
 }
  listdisplay(team,n);
  for(i=0;i<n;i++)
  {
  printf("\n enter your choice:");
  scanf("%d",&num);
  num=num-1;
  display(team,num);
  }
  getch();
  }