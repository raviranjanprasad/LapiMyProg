/*
 * =====================================================================================
 *
 *       Filename:  ArrayList.cpp
 *
 *    Description:  Implements and defines the methods of ArrayList class methods 
 *
 *        Version:  1.0
 *        Created:  02/03/2014 04:09:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
//Constructor of the class arrayList
template <class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity < 1){   //Handles the illegal paramenter value.
		ostringstrem s;
		s << "Initial Capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLenght = initialCapacity; //Assign the arrayLenght with the pased value of inital capacity.
	element = new T[arrayLenght];  //Allocate the array with the initalCapacity 
	listSize = 0;     //As there is no element yet in the array 
}
