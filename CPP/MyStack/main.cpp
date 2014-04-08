#include"Stack.h"

using namespace std;
int main()
{
	//Stack<int> *myStack = new Stack<int>();
	Stack<int> myStack;
	for(int i=0;i<10;i++)
		myStack.push(i+10);
		//myStack->push(i+10);

	for(int i=0;i<12;i++){
		int res=myStack.pop();
		//int res=myStack->pop();
		cout <<"Popped Element :"<<res<<endl;
	}
	
	return 0;
}
