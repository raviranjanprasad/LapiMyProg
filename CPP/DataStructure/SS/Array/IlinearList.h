/*
 * =====================================================================================
 *
 *       Filename:  IlinearList.c
 *
 *    Description:  Interface for the Linear List.
 *
 *        Version:  1.0
 *        Created:  02/03/2014 02:50:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#ifndef _ILINEARLIST_
#define _ILINEARLIST_

#include<iostream>
#include<string>

using namespace std;

template <class T>
class ILinearList{
public:
	virtual int size() const =0;
	virtual bool empty() const = 0;
	virtual T &get(int index) const = 0;
	virtual int indexof(const T &element) const = 0;
	virtual void insert(int index,const T &element);
	virtual void erase(int index, const T &element);
	virtual void display(const T &element) const = 0;
	virtual ~ILinearList();
};
#endif

