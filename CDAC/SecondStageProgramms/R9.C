
                /*PROGRAM TO SORT A STRING IN ALPHBETIC ORDER*/

void main()
 {
  char str[30],*s,temp;
  int i,j;
  clrscr();
  printf("\n enter the string::");
  gets(str);
  s=str;
  for(i=0;str[i]!='\0';i++)
    for(j=i+1;str[j]!='\0';j++)
     {
     if(*(s+i)>*(s+j))
      {
       temp=*(s+i);
       *(s+i)=*(s+j);
       *(s+j)=temp;
      }
    }
    printf("\n The sorted string is::");
    puts(str);
    getch();
   }
