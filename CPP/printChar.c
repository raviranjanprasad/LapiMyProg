#include<stdio.h>
#include<stdlib.h>


int main()
{
   int ch;
   char chr;
   for(ch = 125; ch < 126; ch++){
      chr = ch;
      printf("ch=%d,chr=%s\n",ch,chr);
   }
   return 0;
}
