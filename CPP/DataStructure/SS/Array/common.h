/*
 * =====================================================================================
 *
 *       Filename:  common.c
 *
 *    Description:  This is the common header file used across all the application.
 *
 *        Version:  1.0
 *        Created:  02/09/2014 08:57:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

#ifndef _COMMON_H
#define _COMMON_H
#include<iostream>
#include<string>
#include <cstring>
#include<algorithm>
#include<exception>

using namespace std;

/*class MyException {
 	 char *str_what;
public:
 	MyException(char *str=0):str_what(new char[strlen(str) +1]){
	     strcpy(str_what,str);
	}
	void msg(){
	  cout <<str_what<<endl;
	}
};*/


class MyException {
 	 string str_what;
public:
 	MyException(string str=0):str_what(str){
	}
	void msg(){
	  cout <<str_what<<endl;
	}
};

template <class T>
void display(T *arr,int len){
  for(int i=0;i<len;i++) cout<< arr[i] <<"  ";
  cout<<endl;
}

template <class T>
void changeLength1D(T* arr,int oldLen, int newLen){
	if (newLen < 0){
		throw MyException("newLen must be >=0");
	}

   	T *temp = new T[newLen];
	copy(arr,arr+oldLen,temp);
	delete [] arr;
	arr = temp;
}
#endif
