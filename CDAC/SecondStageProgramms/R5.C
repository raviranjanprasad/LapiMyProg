
                       /*FUNCTION TO EXTRACT A SUBSTRING FORM A STRING*/

/* FUNCTION TO EXTRACT A PORTION OF STRING */
  strext(char str[],int m,int n)
   {
    char str2[20],*s,*p;
    int i,j;
    j=n+m;
    s=str;
    p=str2;
    while(*p!='\0')
     {
      for(i=1;i<=n;i++)
	*s++;
      for(i=n;i<=j;i++)
       *p++=*s++;
       *p='\0';
      }
       puts(str2);
    }

/* MAIN FUNCTION */
void main()
 {
   char str[20];
   int m,n;
   clrscr();
    printf("\n enter the string:");
    gets(str);
    printf("\n enter the no. of char to be extracted:");
    scanf("%d",&m);
    printf("\n enter the no of char after which extaction starts:");
    scanf("%d",&n);
    strext(str,m,n);
    getch();
    }