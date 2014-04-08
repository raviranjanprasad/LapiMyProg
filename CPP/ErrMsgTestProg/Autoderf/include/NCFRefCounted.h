#ifndef NCFREF
#define NCFREF 
typedef long NcfReferenceCnt;
class NCFRefCounted
{
        public:
                NCFRefCounted();
                NcfReferenceCnt referenceObject() const;
                NcfReferenceCnt dereferenceObject() const;

                /**
                * Get the current reference count
                *
                * @return referenceCnt
                **/
                NcfReferenceCnt getReferenceCnt() const;

        protected:

                /**
                *
                * Destructor
                *
                * @author: Mark Ditto
                **/
                virtual ~NCFRefCounted();

                private:

                /*************************************************/
                /******************* Variables *******************/
                /*************************************************/

                mutable long m_refCnt;
};
static const NcfReferenceCnt s_initRef = 1;

NCFRefCounted::NCFRefCounted()
        : m_refCnt(s_initRef)
{
}

NcfReferenceCnt NCFRefCounted::referenceObject() const
{
        return ++m_refCnt;
}

NcfReferenceCnt NCFRefCounted::dereferenceObject() const
{

        NcfReferenceCnt i = --m_refCnt;
        if (0 == i)
        {
                delete this;
        }
        return i;
}

NcfReferenceCnt NCFRefCounted::getReferenceCnt() const
{
        return m_refCnt;
}

NCFRefCounted:: ~NCFRefCounted(){}
/**
* A template function that will increase the reference count of an object
* and return it's pointer.  Handy for AutoDereference
**/
template< class T > const T* refObject(const T* o)
{
        if (o)
        {
                o->referenceObject();
        }
        return o;
}

/**
* A template function that will increase the reference count of an object
* and return it's pointer.  Handy for AutoDereference
**/
template< class T > T* refObject(T* o)
{
        if (o)
        {
                o->referenceObject();
        }
        return o;
}

/**
* Function that will decrease the reference count of an object allowing
* for a null pointer object
**/
inline void derefObject(const NCFRefCounted* o)
//template< class T > void derefObject(T* o)
{
        if (o)
        {
                o->dereferenceObject();
        }
}

/**
* A simple class to automatically dereference an object when it goes out of scope
*
* @author: Mark Ditto
*
**/
#endif

