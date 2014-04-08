/* FILE PROG. FOR EXTRACT CHAR STRING*/
#include<stdio.h>
#include<conio.h>
main()
{
  char arr[50],arr1[50];
  char *p,*q;
  int i;
  p=arr;
  q=arr1;
  clrscr();
  printf("\nEnter Any Char String");
  gets(arr);
  while(*p)
   {
    *q=*p;
    if(*p=='F'||*p=='f')
     {
      *p++;
       if(*p=='r');
	{
	 *p++;
	  if(*p=='o')
	   {
	    *p++;
	     if(*p=='m')
	      {
		*q++='t';
		*q++='o';
	       }
	      else
	       {
		for(i=0;i<=3;i++)
		 *p++=*q++;
		}
	  else
	   {
	    for(i=0;i<=2;i++)
	     *p++=*q++;
	   }
       else
       {
	for(i=0;i<=1;i++)
	 *p++=*q++;
       }
    else
    {
     *p=*q;
     *p++;
    }
  getch();
 }