#include<iostream>
#include<memory>
#include<cstring>

using namespace std;

void printProduct(int arr[],int size)
{
    int temp=1;

    int *prod = new int[size];
    memset(prod,1,size);

    for(int i=0;i<size;i++)
    {
       prod[i] = temp;
       temp *= arr[i];
    }

    temp =1;

    for(int i=size-1;i>=0;i--)
    {
      prod[i] *=temp;
      temp *=arr[i];
    }

    for(int i=0;i<size;i++)
     cout <<prod[i] <<"   ";

    cout<<endl;
}

int main()
{
   int arr[]={10,3,5,6,2};
   int sz=sizeof(arr)/sizeof(int);
   printProduct(arr,sz);
    
}
