/*
 * =====================================================================================
 *
 *       Filename:  testVarArgs.c
 *
 *    Description:  This is to test if one variable no args can be pass as a argument
 		    to another vaiable no args funciton or not
 *
 *        Version:  1.0
 *        Created:  02/12/2014 06:47:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>

char *vfmt(const char *format, va_list args)
{
    //va_list args;
    //va_start(args, format);
    int size = strlen(format) * 2;
    char* buffer = (char*)malloc(size);
    while (vsprintf(buffer, format, args) < 0)
    {
       free(buffer);
       size *= 2;
       buffer = (char*)malloc(size);
    }

    return buffer;
}

char *fmt(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char *res = vfmt(format, args);
    va_end(args);
    return res;
}

int main()
{
    char *str = fmt("Hello my name is %s and EmpID %d!\n", "Ravi",123903);
    printf("%s\n",str);
    return 0;
}
