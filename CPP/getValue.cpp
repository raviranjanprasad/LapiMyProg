#include<iostream>

using namespace std;

void fun(int *p){
  cout <<*p << endl;
}
int main(){
  int *p;
  p =  new int[10];
  fun(p);
}
