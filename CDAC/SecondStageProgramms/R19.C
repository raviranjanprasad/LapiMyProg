
           /*PROGRAM FOR DIFFERENT INPUT AND OUTPUT*/

#include<stdio.h>
#include<conio.h>
/*FUNCTION FUNA*/
 void funa()
 {
  long n=40000;
  int n1=0,n2=0,n3=0;
  clrscr();
  printf("%d%d%d%-12ld",n1,n2,n3,n);
 /*printf("%08ld",n);*/
  getch();
  }
  /*FUNCTION FUNB*/
  void funb ()
  {
   int  hex=0;
   clrscr();
   printf("\n Enter a number::");
   scanf("%x",&hex);
   printf("%#0x",hex);
   getch();
   }
  /*FUNCTION FUNC*/
   void func()
   {
    int n=200;
    clrscr();
    printf("%d",n);
    printf("\n%d",+n);
    printf("\n%d",-n);
    getch();
    }
 /*FUNCTION FUND*/
   void fund()
   {
   int n=100;
   clrscr();
   printf("%#0x",n);
   getch();
   }

/*FUNCTION FUNE*/
 void fune()
  {
  char str[50];
  clrscr();
  printf("\nEnter characters::");
  scanf("%[^p]",str);
  printf("%-50s",str);
  getch();
  }

 /*FUNCTION FUNF*/
  void funf()
  {
   float n=1.234;
   clrscr();
   printf("%09.3f",n);
   getch();
   }

/*FUNCTION FUNG*/
  void fung()
  {
   int hh,mm,ss;
   clrscr();
   printf("\nEnter the time in format of hh:mm:ss::");
   scanf("%d%*c%d%*c%d",&hh,&mm,&ss);
   printf("%d %d %d",hh,mm,ss);
   getch();
   }

 /*FUNCTION FUNH*/
 void funh()
 {
  char str1[50],str2[50];
  char *p,*q;
  clrscr();
  p=str1;
  q=str2;
  printf("\nEnter a String with quotation marks");
  gets(str1);
  while(*p)
  {
    if(*p=='"')
     p++;
     else
     *q++=*p++;
     }
     *q='\0';
     puts(str2);
     getch();
     }
/* FUNCTION FUNI
 void funi()
  {  */


/* FUNCTION MAIN*/
void main()
{
 char ch;
 int flag=1;
 clrscr();
 do
 {
 printf("\n\t\t------------------------------------");
 printf("\n\t\t MENU FOR DIFFERENT INPUT AND OUTPUT");
 printf("\n\t\t-------------------------------------");
 printf("\n\ta.print unsigned integer 4000 left justified in a 15 -digit field with 8 digit");
 printf("\n\tb.Read a hexadecimal value into a variable hex");
 printf("\n\tc.print 200 with and without a sign");
 printf("\n\td.print 100 in hexadecimal form preceded by ox");
 printf("\n\te.Read characters into array str untill the letter p is encountered");
 printf("\n\tf.Print 1.234 in a 9 digit field with preceding zeors");
 printf("\n\n\tg.Read a time of the form hh:mm:ss, storing the parts of the time in the integer variable hour, minute and sencod");
 printf("\n Skip the colons(:) in the input stream and display it. use the");
 printf("\n assingnment supperession character.");
 printf("\n\n\th.Read a string of the form characters form the standard input. Store the string in character");
 printf("\narry str. Eliminate the quotation marks form the input stream and disply it.");
 printf("\n\n\ti.Read a time of the form hh:mm:ss storing the parts of the ftime in the integer variables hour");
 printf("\nminute and second. Skip the colons(:) in the input stream and dispaly it.");
 printf("\n Do not use trhe assignment-suppression character.");
 printf("\n\n\tj.EXIT");
 printf("\nENTER YOUR CHOICE AS(a/b/c/d/e/f/g/h/i/j)::");
 ch=getche();
 switch(ch)
   {
     case 'a':
	     funa();
	     break;
     case 'b':
	    funb();
	    break;
     case 'c':
	    func();
	    break;
    case 'd':
	     fund();
	     break;

     case 'e':
	    fune();
	    break;

    case 'f':
	    funf();
	    break;
      case 'g':
	     fung();
	     break;

     case 'h':
	    funh();
	    break;
    /*  case 'i':
	     funi();
	     break;*/
     case 'j':
	    flag=0;
	    break;
      default:
	       printf("\n Your choice is wrong::");
	 }
      }while(flag);
 getch();
}
