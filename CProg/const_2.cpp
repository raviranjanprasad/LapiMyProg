#include <iostream>
using namespace std;
 
int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
    //return (*ptr + 10);
}
 
int main(void)
{
    const int val = 10;
    const int *ptr = &val;
    //int *ptr1 = const_cast <int *>(ptr);
    char *ch = (char*) ptr;
    cout << fun(ch);
    return 0;
}