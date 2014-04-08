#include<iostream>
#include<string>

using namespace std;

void FillValue(int **ptr){
   if(ptr){
     for(int i=0;i<5;i++){
        (*ptr)[i] = i + 10;
     }     
   }
}

void display(int **ptr){
  if(ptr){
    for(int i=0;i<5;i++){
      cout <<(*ptr)[i] <<endl;
  }
}
}

int main(){
  int *p;
  p = new int[5];
  FillValue(&p);
  display(&p);

  return 0;  
}
