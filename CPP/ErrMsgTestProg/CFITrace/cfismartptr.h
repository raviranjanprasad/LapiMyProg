#ifndef CFISMRTPTR
#define CFISMRTPTR
#include<iostream>
#include<string>

using namespace std;

namespace VFI_PDK_NAMESPACE {

template <class T> class CFiNullAllocator
{

public:
    T *operator()()
    {
        return NULL;
    }

    void destroy(T *obj)
    {
        delete obj;
    }
};

// @desc This class implements a counted smart pointer.  class T
//       must implement Increment() and Decrement() functions.
//       These are best implemented by having one's class T
//       derive from CFiRefCount
// @seealso CFiRefCount
template <class T, class A = CFiNullAllocator<T> > class CFiSmartPtr
{

protected:

    T* m_ptr;

public:

    explicit CFiSmartPtr(bool allocateInstance = false)
        : m_ptr(NULL)
    {
        if(allocateInstance)
        {
            A instanceAllocator;
            acquire(instanceAllocator());
        }
    }
    explicit CFiSmartPtr(T* ptr)
        : m_ptr(NULL)
    {
        if(ptr){
            acquire(ptr);
        }
    }

    CFiSmartPtr(const CFiSmartPtr<T, A> &sp)
        : m_ptr(sp.m_ptr)
    {
        if(m_ptr)
            m_ptr->increment();
        
    }

    ~CFiSmartPtr()
    {
        release();
    }

    CFiSmartPtr<T, A> &operator = (const CFiSmartPtr<T, A> &sp)
    {
        if (this != &sp)
        {
            acquire(sp.m_ptr);
        }
        return *this;
    };

    CFiSmartPtr<T, A> &operator = (T *ptr)
    {
        if(m_ptr != ptr){
            acquire(ptr);
        }
        return *this;
    }


    bool operator == (const CFiSmartPtr<T, A> &sp) const
    {
        return m_ptr == sp.m_ptr;
    }

    bool operator == (const T* ptr) const
    {
        return m_ptr == ptr;
    }

    bool operator == (const T& ref) const
    {
        return *m_ptr == ref;
    }

    bool operator != (const CFiSmartPtr<T, A> &sp) const
    {
        return m_ptr != sp.m_ptr;
    }

    bool operator != (const T* ptr) const
    {
        return m_ptr != ptr;
    }

    bool operator != (const T& ref) const
    {
        return *m_ptr != ref;
    }

    bool operator ! () const
    {
        if(m_ptr == NULL)
            return true;

        return false;
    }

    T* operator -> () const
    {
        return m_ptr;
    }

    T& operator * () const
    {
        return *m_ptr;
    }

    operator T* () const
    {
        return m_ptr;
    }

    T* getPointer() const
    {
        return m_ptr;
    }

    int release(){
        int count = -1;
        if(m_ptr){
            count = (int)m_ptr->decrement();
            if(count == 0){
                //Here we increment the the counter just before deletion
                //just in case there's logic in the destructor that causes the
                //object to be incremented and deremented again via another
                //function using a temporary smart pointer.  By doing this quick Increment()
                //have added insurance that that logic will go through without triggering the
                //destructor a second time.
                m_ptr->increment();
                A instanceAllocator;
                instanceAllocator.destroy(m_ptr);
            }
            m_ptr = NULL;
        }
        return count;
    }

    int acquire(T *ptr)
    {
        int count = -1;
        if(m_ptr != NULL)
        {
            count = release();
        }
        if(ptr){
            m_ptr = ptr;
            count = m_ptr->increment();
        }
        else {
            m_ptr = NULL;
        }
        return count;
    }

};

class CFiRefCount {

protected:

    volatile unsigned int __m_refCount;

public:

    CFiRefCount() : __m_refCount(0)
    {
    }

    virtual ~CFiRefCount(){}

    virtual unsigned int increment()
    {
        return ++__m_refCount;
    }
    virtual unsigned int decrement()
    {
        return --__m_refCount;
    }
    virtual unsigned int getCount()
    {
        return __m_refCount;
    }

};

}
#endif
