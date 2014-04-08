#ifndef ARR_STK
#define ARR_STK
#include"common.h"
#include"stack.h"

template<class T>
class ArrayStack:public stack<T>{
    enum {DEF_SIZE  = 10};
    int m_cap;
    int m_top;
    T *m_stk;
public:
    ArrayStack(int cap=DEF_SIZE):m_cap(cap),m_top(-1),m_stk(new T[cap]){}
    bool isEmpty() const;
    int size() const;
    void pop()throw(StackEmpty);
    void push(const T &)throw(StackFull) ;
    T &top()throw(StackEmpty);
    ~ArrayStack();
};
#endif
