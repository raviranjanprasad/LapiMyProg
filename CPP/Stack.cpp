#include"Stack.h"

template<class T>
Stack<T>::Stack(){m_top = -1;}

template<class T>
bool Stack<T>::isEmpty(){return m_top == -1;}

template<class T>
T Stack<T>::pop(){
   if(isEmpty()){
      cout<<"The Stack in Empty\n";return;
   }
	   //throw UnderflowException();
   return m_array[m_top--];
}

template<class T>
T &Stack<T>::top(){
   if(isEmpty()){
    cout <<"Stack Empty\n";return;
   }
	   //throw UnderflowException();
   return m_array[m_top];
}

template<class T>
void Stack<T>::push(const T &obj){
	if(m_top == m_array.size() - 1)
		m_array.resize(m_array.size() * 2 );

	m_array[++m_top] = obj;
}

template<class T>
void Stack<T>::makeEmpty(){
	m_top = -1;
}

template<class T>
Stack<T>::~Stack(){
	cout <<"Stack Destructor called\n";
}

