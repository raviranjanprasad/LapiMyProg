#include"ArrayStack.h"

template<class T>
ArrayStack<T>::~ArrayStack(){
    cout<<"Array Stack Destructor called\n";
    delete [] m_stk;
}

template<class T>
bool ArrayStack<T>::isEmpty() const{
    return (m_top < 0 ? true: false);
}

template<class T>
int ArrayStack<T>::size() const{ return m_top + 1;}

template<class T>
void ArrayStack<T>::pop() throw(StackEmpty){
    if(isEmpty()) throw StackEmpty("Pop from an Empty Stack Not Allowed\n");
    m_top--;
}

template<class T>
void ArrayStack<T>::push(const T &obj) throw(StackFull){
    int sz = size();
    if(sz == m_cap) throw StackFull("Stack is Full");
    m_stk[++m_top]= obj;
}

template<class T>
T &ArrayStack<T>::top()throw (StackEmpty){
    if(isEmpty()) throw StackEmpty("Stack is Empty\n");
    return m_stk[m_top];
}

int main()
{
    ArrayStack<int> A; 
    try{
    A.push(7); 
    A.push(13); 
    A.push(9); 
    }catch(StackFull &sf){
        sf.getMessage();
    }

    cout<<"Stack Size "<<A.size() <<endl;

    try{
    cout <<"Stack Element on top="<< A.top() << endl;
    A.pop(); 
    cout << A.top() << endl;
    cout << A.top() << endl; 
    A.pop(); 
    }catch(StackEmpty &sf){
      sf.getMessage();
    }

    ArrayStack<string> B(10);

    try{
    B.push("Bob"); 
    B.push("Alice"); 
    B.push("Eve"); 
    }catch(StackFull &sf){
        sf.getMessage();
    }

    try{
    cout <<"Stack Element on top="<< B.top() << endl;
    B.pop(); 
    cout <<"Stack Element on top="<< B.top() << endl;
    }catch(StackEmpty &sf){
        sf.getMessage();
    }
    return 0;
}
