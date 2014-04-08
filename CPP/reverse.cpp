#include<iostream>
#include<cstring>

using namespace std;

void swap(char *beg, char *end){
   char temp;
   temp = *beg;
   *beg = *end;
   *end = temp;
}

void reverse(char *word){

   char *start,*end;
   start = word;
   end = start + strlen(word) - 1;
   while(start < end)
      swap(start++,end--);
   
}

int main()
{
    char word[]="This is to test";
	reverse(word);
	cout << word << endl;
}
