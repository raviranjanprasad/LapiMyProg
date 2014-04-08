#ifndef LINKLIST_H
#define LINKLIST_H

/*Template classes are required to define in the same header file,
otherwise it give undiefined symbols compilation error.*/
#include <common.h>
#include <linkedListIterator.h>
template <class T>
class linkedList{
public:
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	T front() const;
	T back() const;
	virtual bool search(const T& searchItem) const = 0;
	virtual void insertFirst(const T& newItem) = 0;
	virtual void insertLast(const T& newItem) = 0;
	virtual void deleteNode(const T& deleteItem) = 0;
	linkedListIterator<T> begin();
	linkedListIterator<T> end();
	linkedList();
	linkedList(const linkedList<T>& otherList);
	const linkedList<T>& operator= (const linkedList<T>&);
	virtual ~linkedList();

protected:
	int count;
	node<T> *first;
	node<T> *last;
private:
    void copyList(const linkedList<T>& otherList)const;
};

template <class T>
bool linkedList<T>::isEmptyList() const{
	return (first ==  NULL);
}



template <class T>
linkedList<T>::linkedList(){
	first = last = NULL;
	count = 0;
}


template <class T>
linkedList<T>::destroyList(){
	node<T> *temp;
	while(first != NULL){
		temp = first;
		first = first->link;
		delete temp;
	}

	last  = NULL;
	count = 0;
}


template <class T>
linkedList<T>::initializeList(){
	destroyList();
}



template <class T>
linkedList<T>::print() const{
	node<T> *current;
	current = first;
	while(current != NULL){
        cout<<current->info <<"-->";
        current = current->link;
	}
}


template <class T>
int linkedList<T>::length(){
    return count;
}


template <class T>
T linkedList<T>::front() const{
    assert(first != NULL);
    return first->info;
}


template <class T>
T linkedList<T>::back() const{ 
    assert(last != NULL);
    return last->info;
}


template <class T>
lnkedListIterator<T> inkedList<T>::begin(){
    lnkedListIterator<T> temp(first);
    return temp;
}


template <class T>
lnkedListIterator<T> inkedList<T>::end(){
    lnkedListIterator<T> temp(NULL);
    return temp;
}

template <class T>
void linkedList<T>::copyList(const linkedList<T>& otherList){
    node<T> *newNode;
    node<T> *current;

    if(first != NULL)
        destroyList();

    if(otherList.first ==  NULL){
        first = NULL;
        last = NULL;
        count = 0;
    }

    else{
        current = otherList.first;
        count =  otherList.count;

        first = new node<T>;
        first->info = current->info;
        first->link =  NULL;

        last =  first;
        current = current->link;

        while(current != NULL){
            newNode =  new node<T>;
            newNode->info = current->info;
            newNode->link =  NULL;
            last->link=newNode;
            last = newNode;

            current =  current->link;
        }
    }
}

template <class T>
linkedList<T>::linkedList(const linkedList<T> &otherList){
    first = NULL;
    copyList(otherList);
}

template <class T>
const linkedList<T>& linkedList<T>::operator=(const linkedList<T> &otherList){
    if(this != &otherList){
        copyList(otherList);
    }

    return *this;
}

template <class T>
linkedList<T>::~linkedList(){
    destroyList();
}

#endif
