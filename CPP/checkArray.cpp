#include <iostream>
using namespace std;
int addNumbers(int number1, int number2)
  {
       std::cout << "Entering function " <<___func___<< std::endl;
       int result = number1 + number2;
       return result;
  }

int main()
{
        int res=addNumbers(23,45);
        cout << "Res::" << res;
	return 0;
}

