// operator new[] example
#include <iostream>     // std::cout
#include <new>          // ::operator new[]

struct MyClass {
  int data;
  MyClass() {std::cout << '*';}  // print an asterisk for each construction
};

int main () {
  std::cout << "constructions (1): ";
  // allocates and constructs five objects:
  MyClass * p1 = new MyClass[5];
  std::cout << '\n';

  std::cout << "constructions (2): ";
  // allocates and constructs five objects (nothrow):
  MyClass * p2 = new (std::nothrow) MyClass[5];
  std::cout << '\n';

  std::cout << "constructions (3): ";
  // allocates storage for five objects, but does not construct them:
  MyClass * p3 = static_cast<MyClass*> (operator new (sizeof(MyClass[5])));
  std::cout << '\n';

  std::cout << "constructions (4): ";
  // constructs five objects at p3, but does not allocate:
  new (p3) MyClass[5];
  std::cout << "size::"<<sizeof( MyClass[5])<<'\n';

  delete[] p3;
  delete[] p2;
  delete[] p1;

  return 0;
  
}
