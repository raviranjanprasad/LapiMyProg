/*
 * =====================================================================================
 *
 *       Filename:  multipleObj.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/13/2014 12:41:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
#include <auto_ptr.h>

int main()
{
    typedef std::auto_ptr<Object> object_ptr;
    std::vector<object_ptr> some_values;
    some_values.push_back(new Object(10));
    some_values.push_back(new Object("Hello there"));
    some_values.push_back(new Object(std::string("Wow!")));
    std::string* p = 
         dynamic_cast<std::string*>(some_values.back().get());
    assert(p);

    (*p) += " That is great!\n";
    std::cout << *p;
    return 0;
}

~

~
 


