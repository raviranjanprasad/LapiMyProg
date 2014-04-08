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

#include <string>
#include <cstdio>
#include <cstdarg>

std::string vfmt(const std::string& format, va_list args)
{
    int size = format.size() * 2;
    char* buffer = new char[size];
    while (vsprintf(buffer, format.c_str(), args) < 0)
    {
       delete[] buffer;
       size *= 2;
       buffer = new char[size];
    }

    return std::string(buffer);
}

std::string fmt(const std::string& format, ...)
{
    va_list args;
    va_start(args, format);
    std::string res = vfmt(format, args);
    va_end(args);
    return res;
}

int main()
{
    std::string s = fmt("Hello my name is %s and EmpID %d!\n", "Ravi",123903);
    printf(s.c_str());
    return 0;
}
