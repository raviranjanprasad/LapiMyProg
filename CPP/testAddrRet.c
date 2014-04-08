#include<stdio.h>


//using namespace std;

/*class A
{
  public:
    A(){}
    ~A(){}
};*/
int *fun(int a, int b)
{
   /*A obj;
   return &obj;*/
   
   int j = 10;
   int *ptr = (int*)j;

   return ptr;
  
}


int main()
{
  
  //A ret = fun(10,20);


  int *res = fun(10,20);

  printf("%d\n",*res);
  //cout <<res << endl;
  return 0;
}
