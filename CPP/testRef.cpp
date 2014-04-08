#include<iostream>

using namespace std;

int main()
{
   int a = 10;
   int b = 20;
   int &ref = a;
   int &ref = b;
   cout<<"ref = " <<ref <<endl;
   return 0;
   
}
