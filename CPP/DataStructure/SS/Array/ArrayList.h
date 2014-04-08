/*
 * =====================================================================================
 *
 *       Filename:  ArrayList.h
 *
 *    Description:  This calss inheritates the ILinearList Interface and implementes the
		    the array calls with different methods, this is a dynamic growing
		    array.
 *
 *        Version:  1.0
 *        Created:  02/03/2014 03:23:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */

template<class T>
class arrayList : public ILinearList<T>
{
protected:
	
	T* element;
	int arrayLength;
	int listSize;
	void checkIndex(int theIndex) const; //throw illegelIndex if the Index invalid.
public:
	arrayList(int inittialCapacity = 10);
	arrayList(const arrayList<T> &);
	
	//Ineterface ILinearList methods
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

	// additional method
	int capacity() const {return arrayLength;}

	~arrayList() {delete [] element }

};


