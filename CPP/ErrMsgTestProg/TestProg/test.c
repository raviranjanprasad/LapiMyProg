/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2014 10:41:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

/* vsnprintf example */
#include "aupe.h"

void PrintFError ( const char * format, ... )
{
 // char buffer[256];
  char *buffer=(char*)malloc(256);
  va_list args;
  va_start (args, format);
  vsnprintf (buffer,256,format, args);
  perror (buffer);
  va_end (args);
  free(buffer);
}

int main ()
{
   FILE * pFile;
   char szFileName[]="myfile.txt";

   pFile = fopen (szFileName,"r");
   if (pFile == NULL)
     PrintFError ("Error opening '%s'",szFileName);
   else
   {
     // file successfully open
     fclose (pFile);
   }
   return 0;
}

