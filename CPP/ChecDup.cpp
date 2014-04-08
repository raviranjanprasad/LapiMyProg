#include<iostream>
#include<cstdlib> /*for calling of calloc from  c++ code*/

using namespace std;

int findMax(int arr[], int size)
{
   int max= arr[0];
   
   for(int i=0;i<size;i++)
   {
      if(arr[i] > max)
       max = arr[i];
   }

   return max;
}

void printDuplicate(int arr[], int size)
{
    int max=findMax(arr,size);

     //int *count = (int*)calloc(sizeof(int),max);
     int *count = new int[max];

     for(int i=0;i<size;i++)
     {
        if(count[arr[i]] == 1)
           cout<<"Duplicate :"<<  arr[i] <<endl;
        else
           count[arr[i]]++; 
     }
}

int main()
{
   int arr[] = {4,2,4,9,5,10,12,9,12};
   int arr_size = sizeof(arr)/sizeof(int);
   printDuplicate(arr,arr_size);
}

