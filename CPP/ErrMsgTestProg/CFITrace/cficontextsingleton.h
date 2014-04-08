#ifndef SINGLETON
#define SINGLETON
#include"cfismartptr.h"
namespace VFI_PDK_NAMESPACE {

template <class T> class CFiContextSingletonAllocator
{

public:
    T *operator()()
    {
        return new T;
    }

    void destroy(T *obj)
    {
        delete obj;
    }
};


template <class T, class Context = T>
class CFiContextSingleton
{

    CFiContextSingleton();
    CFiContextSingleton(const CFiContextSingleton<T, Context> &);
    ~CFiContextSingleton(){}


public:
    typedef CFiSmartPtr<T, CFiContextSingletonAllocator<T> > CFiSingletonSmartPtr;

    static void release()
    {
        instance(true);
    }

    static CFiSingletonSmartPtr instance(bool releaseInstance=false)
    {
        static CFiSingletonSmartPtr contextInstance;
/*#ifdef VXFI_MULTI_THREAD
        static ACE_SYNCH_MUTEX mutex;

        // We could use a DCLP, but see C++ and the perils of DCLP
        // by Sutter et. al. If this is a problem, we can optimize
        // it using DCLP.
        ACE_GUARD_RETURN(ACE_SYNCH_MUTEX,
                         mon,
                         mutex,
                         contextInstance);

#endif*/

        if(releaseInstance)
        {
            contextInstance.release();
        }
        else
        {
            if(contextInstance.getPointer() == NULL){
                contextInstance = CFiSingletonSmartPtr(true);
            }
        }
        return contextInstance;
    }
};
}
#endif
