/*
 * =====================================================================================
 *
 *       Filename:  arrayListType.cpp
 *
 *    Description:  Implementation of arrayListType interface.
 *
 *        Version:  1.0
 *        Created:  03/15/2014 02:00:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#include <aupecpp.h>

template <class T>
 class arrayListType{
 public:
        //class methods
        bool isEmpty() const;
        bool isFull() const;
        int listSize() const;
        int maxListSize() const;
        bool isItemAtEqual(int , const T&) const; //First argument is the index location
        void insertAt(int, const T&);
        void insertAtEnd(const T&);
        void removeAt(int);
        void retrieveAt(int, T &) const;
        void replaceAt(int , const T& );
        void clearList();
        int seqSearch(const T& ) const;
        void insert(const T& );
        void remove(const T&);
        void print() const;

        //Class basic entities
        arrayListType(int maxSz=5);
        arrayListType(const arrayListType<T> &);
        const arrayListType<T>& operator=(const arrayListType<T>&);
        virtual ~arrayListType();
protected:
        T *m_list;
        int m_length;
        int m_maxSize;

 };
 
template <class T>
bool arrayListType<T>::isEmpty() const{

	return (m_length == 0);
}

template <class T>
bool arrayListType<T>::isFull() const
{
	return (m_length == m_maxSize);
}

template <class T>
int arrayListType<T>::listSize() const
{
	return m_length;
}

template <class T>
int arrayListType<T>::maxListSize() const
{
	return m_maxSize;
}

template <class T>
void arrayListType<T>::print() const
{
	for (int i = 0; i < m_length; i++)
		cout << m_list[i] << " ";
	cout << endl;
}

template <class T>
bool arrayListType<T>::isItemAtEqual (int location, const T& item) const
{
	return(m_list[location] == item);
}

template <class T>
void arrayListType<T>::insertAt(int location, const T& insertItem)
{
	if (location < 0 || location >= m_maxSize)
		cerr << "The position of the item to be inserted " << "is out of range" << endl;
	else if (m_length >= m_maxSize) //m_list is full
			cerr << "Cannot insert in a full m_list" << endl;
		else
		{
			for (int i = m_length; i > location; i--)
				m_list[i] = m_list[i - 1]; //move the elements down
			m_list[location] = insertItem; //insert the item at the
			//specified position
			m_length++; //increment the m_length
		}
} //end insertAt

template <class T>
void arrayListType<T>::insertAtEnd(const T& insertItem)
{
	if (m_length >= m_maxSize) //the m_list is full
		cerr << "Cannot insert in a full m_list" << endl;
	else
	{
		m_list[m_length] = insertItem; //insert the item at the end
		m_length++; //increment the m_length
	}
} //end insertEnd

template <class T>
void  arrayListType<T>::removeAt(int location)
{
	if (location < 0 || location >= m_length)
		cerr << "The location of the item to be removed "
			<< "is out of range" << endl;
	else
	{
		for (int i = location; i < m_length - 1; i++)
			m_list[i] = m_list[i+1];
		m_length--;
	}
} //end removeAt

template <class T>
void  arrayListType<T>::retrieveAt
(int location, T& retItem) const
{
	if (location < 0 || location >= m_length)
		cerr << "The location of the item to be retrieved is "
			<< "out of range." << endl;
	else
		retItem = m_list[location];
} //end retrieveAt
template <class T>
	void arrayListType<T>::replaceAt
(int location, const T& repItem)
{
	if (location < 0 || location >= m_length)
		cerr << "The location of the item to be replaced is "
			<< "out of range." << endl;
	else
		m_list[location] = repItem;
} //end replaceAt

template <class T>
void arrayListType<T>::clearList()
{
	m_length = 0;
} //end clearList

template <class T>
arrayListType<T>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;
		m_maxSize = 100;
	}
	else
		m_maxSize = size;
	m_length = 0;
	m_list = new T[m_maxSize];
	assert(m_list != NULL);
}

template <class T>
arrayListType<T>::~arrayListType()
{
	delete [] m_list;
}

template <class T>
arrayListType<T>::arrayListType (const arrayListType<T>& otherList)
{
	m_maxSize = otherList.m_maxSize;
	m_length = otherList.m_length;
	m_list = new T[m_maxSize]; //create the array
	assert(m_list != NULL); //terminate if unable to allocate
	//memory space
	for (int j = 0; j < m_length; j++) //copy otherList
		m_list [j] = otherList.m_list[j];
} //end copy constructor

template <class T>
const arrayListType<T>& arrayListType<T>::operator= (const arrayListType<T>& otherList)
{
	if (this != &otherList) //avoid self-assignment
	{
		delete [] m_list;
		m_maxSize = otherList.m_maxSize;
		m_length = otherList.m_length;
		m_list = new T[m_maxSize]; //create the array
		assert(m_list != NULL); //if unable to allocate memory
		//space, terminate the program
		for (int i = 0; i < m_length; i++)
			m_list[i] = otherList.m_list[i];
	}
	return *this;
}

template <class T>
int arrayListType<T>::seqSearch(const T& item) const
{
	int loc;
	bool found = false;
	for (loc = 0; loc < m_length; loc++)
		if (m_list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class T>
void arrayListType<T>::insert(const T& insertItem)
{
	int loc;
	if (m_length == 0) //m_list is empty
		m_list[m_length++] = insertItem; //insert the item and
	//increment the m_length
	else if (m_length == m_maxSize)
		cerr << "Cannot insert in a full m_list." << endl;
	else
	{
		loc = seqSearch(insertItem);
		if (loc == -1) //the item to be inserted
			//does not exist in the m_list
			m_list[m_length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
				<< "the m_list. No duplicates are allowed." << endl;
	}
} //end insert

template<class T>
void arrayListType<T>::remove(const T& removeItem)
{
	int loc;
	if (m_length == 0)
		cerr << "Cannot delete from an empty m_list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the m_list."
				<< endl;
	}
} //end remove
