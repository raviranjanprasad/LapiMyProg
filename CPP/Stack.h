#ifndef _STACK_H
#define _STACK_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<class T>
class Stack{
public:
	Stack();
	~Stack();
	bool isEmpty();
	T pop();
	T &top();
	void push(const T &);
	void makeEmpty();

private:
    vector<T> m_array;
	int m_top;
};
#endif

