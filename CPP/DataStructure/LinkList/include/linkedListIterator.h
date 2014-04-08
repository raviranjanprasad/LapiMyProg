/*
 * =====================================================================================
 *
 *       Filename:  linkList.c
 *
 *    Description:  Link List Interface class.
 *
 *        Version:  1.0
 *        Created:  03/23/2014 07:10:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

#include <aupecpp.h>
#include <common.h>

template <class T>
class linkedListIterator
{
public:
	linkedListIterator();
	linkedListIterator(node<T> *ptr);
	T operator*();
	linkedListIterator<T> operator++();
	bool operator==(const linkedListIterator<T>& right) const;
	bool operator !=(const linkedListIterator<T>& right) const;
private:
	node<T> *current;
};

template <class T>
linkedListIterator<T>::linkedListIterator(){
	current =  NULL;
}

template <class T>
linkedListIterator<T>:: linkedListIterator(node<T> *ptr){
	current =  ptr;
}




template <class T>
linkedListIterator<T>::operator*(){
	return current->info;
}	


template <class T>
linkedListIterator<T> linkedListIterator<T>::operator++(){
	current =  current->list;
	return *this;
	
}

template <class T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& right) const{
	return (current == right.current);
}

template <class T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& right) const{
        return (current != right.current);
}
