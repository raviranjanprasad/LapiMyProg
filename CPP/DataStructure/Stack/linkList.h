#include"common.h"

//Node for Generic Link List
template<class T>
class SNode{
    T elem;
    SNode<T> *next;
    friend class SLinkList<T>;
};

//Generic Link List
template <class T>
class SLinkedList { // a singly linked list
    public:
        SLinkedList(); // empty list constructor
        ~SLinkedList(); // destructor
        bool empty() const; // is list empty?
        const T& front() const; // return front element
        void addFront(const T& e); // add to front of list
        void removeFront(); // remove front item list
    private:
        SNode<T>* head; // head of the list
};
