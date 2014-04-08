               			 /*FILE-9=32:SUNBEAM*/
	          /*PROGRAM TO SEARCH A WORD FROM A TEXT FILE*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  FILE *fp;
  char word[15],find[15],ch;
  int i=0,pos=1;
  clrscr();
       printf("\n Enter the word which is to be find out::");
       gets(find);
       printf("\n Enter the content of the file::");

      /*FILE WORD.TXT IS OPEN IN THE WRITE MODE*/

   if((fp=fopen("WORD.TXT","w"))==NULL)
    {
     printf("\n The file WORD.TXT is unable to open::");
     exit(1);
    }
     /*WRITE THE CHARACTER IN THE FILE*/

      while((ch=getchar())!=EOF)
       {
	 fputc(ch,fp);
       }
       fclose(fp);
       flushall();

     /* FILE WORD.TXT IS OPEN IN THE READ MODE*/

       if((fp=fopen("WORD.TXT","r"))==NULL)
    {
     printf("\n The file WORD.TXT is unable to open::");
     exit(1);
    }
 /*READS THE WORD IN THE FILE AND COMPARE IT WITH THE WORD WHICH IS
   TO BE FIND OUT*/

       while((ch=fgetc(fp))!=EOF)
	{
	    flushall();
	  if(ch==' '||ch=='\n')
	     {
	      word[i]='\0';
	      if((strcmp(word,find))==0)
	      printf("\n The word::%s  found at position::%d",find,pos);
	      printf("\n");
	      pos++;
	      i=0;
	     }
	  else
	      word[i++]=ch;

	 }
	    if(ch==EOF)
	    word[i]='\0';
	    if((strcmp(word,find))==0)
	   {
	     printf("\n The word is found at position::%d",pos);
	     printf("%s",word);
	   }
	   else
	     printf("\n The word is not exit in the file::");

     getch();
    }