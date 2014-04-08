#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<string>
#include<cstring>
#include<exception>
#include<cstdlib>

using namespace std;

//Generic Runtime Exception
class RuntimeException {             // generic run-time exception
    private:
        string errorMsg;
    public:
        RuntimeException(const string& err) { errorMsg = err; }
        string getMessage() const { return errorMsg; }
};

// Exception thrown on performing top or pop of an empty stack.
class StackEmpty : public RuntimeException {
    public:
        StackEmpty(const string& err) : RuntimeException(err) {}
};

// Exception thrown on performing push operation on stack.
class StackFull: public RuntimeException {
    public:
        StackFull(const string& err) : RuntimeException(err) {}
};
#endif

