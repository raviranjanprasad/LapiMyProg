#include"linkList.h"
#include"stack.h"
#ifndef LINK_STACK
#define LINK_STACK
template<class T>
class LinkStack:public stack<T>{
    SLinkList<T> *list;
    int n;
public:
    LinkStack();
    bool isEmpty() const;
    int size() const;
    void pop()throw(StackEmpty);
    void push(const T &)throw(StackFull) ;
    T &top()throw(StackEmpty);
    ~LinkStack();
};

#endif
