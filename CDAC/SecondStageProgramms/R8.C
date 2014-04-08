
						/*PROGRAM FOR THE ENCRYPTION AND DECRYPTION OF
						                STRING*/

/*PROGRAM FOR ENCRYPTION AND DECRYPTION*/
void main()
{
char string[30],ptr;
int flag;
int i,j,len;
clrscr();
 printf("\n enter the string:");
 printf("\n only alphbates number underscore dot is allowed\n");
 printf("\n string in encrypted form:");
 i=0;
 flag=1;
 do
  {
  ptr=getch();
  if((ptr>=97&&ptr<=122)||(ptr>=65&&ptr<=90)||(ptr>=48&&ptr<=57)||ptr==46||ptr==0||ptr==95)
   {
   string[i]=ptr;
   ptr=15;
   printf("%c",ptr);
    }
    else
    flag=0;
    i++;
 }while(flag);
 len=i;
 printf("\n\n The decrypted form of string is:");
 for(i=0;i<len-1;i++)
 printf("%c",string[i]);
 getch();
 }