#include<stdio.h>
#define VXFITEXT(x) (char *)x
typedef char vfi_char_t;

int LogMessage()
{
   static vfi_char_t         *who = VXFITEXT("LogMessage");
   //Ravi
   FILE *out;
   out = fopen( "output.txt", "w+" );
   if( out != NULL )
	   fprintf( out, " %s\n", who ); 
   //Ravi

   fclose(out);
   return 0;
}
int main(int argc, char *argv[]){
   LogMessage();
   return 0;
  
}
