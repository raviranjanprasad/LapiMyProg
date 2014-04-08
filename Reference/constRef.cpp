#include<iostream>
#include<string>

using namespace std;

int main()
{
  int a=30;
  const int& ref_a=a;
  cout <<"ref_a=" << ref_a <<endl << "a=" <<a <<endl;
  const int b=50;
  const int& ref_b = b;
  cout <<"ref_b=" << ref_b <<endl << "b=" <<b <<endl;
  return 0;
}
