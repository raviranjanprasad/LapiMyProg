#ifndef STACK_H
#define STACK_H
#include"common.h"

template<class T>
class stack{
    public:
        virtual ~stack(){cout <<"Stack Interface Destructor\n";}
        virtual bool isEmpty() const = 0;
        virtual int size() const  = 0;
        virtual void pop()throw(StackEmpty) = 0;
        virtual void push(const T &)throw(StackFull) = 0 ;
        virtual T &top()throw(StackEmpty) = 0;
};
#endif
