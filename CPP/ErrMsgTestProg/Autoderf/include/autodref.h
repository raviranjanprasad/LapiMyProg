#ifndef AUTODEREF
#define AUTODEREF
#include"NCFRefCounted.h"
template<class T>
class AutoDereference
{
        public:

                /**
                *
                * Constructor
                *
                * @author Mark Ditto
                **/
                AutoDereference()
                        : m_object (0)
                {
                };

                /**
                *
                * Constructor
                *
                * Object's reference count is assumed to already be incremented
                *
                * @author Mark Ditto
                *
                * @param object - object to save in autodereference constructor
                **/
                AutoDereference(
                        const T *object
                        ) : m_object(const_cast<T*>(object))
                {};

                /**
                *
                * Copy constructor
                *
                * Reference count is automatically incremented
                *
                * @param object - object to copy a reference to
                **/

                AutoDereference(
                        const AutoDereference<T> &object
                        ) : m_object(0)
                {
                        *this = refObject(*object);
                };


                /**
                *
                * Destructor
                *
                * @author Mark Ditto
                **/
                virtual ~AutoDereference()
                {
                        *this = 0;
                };

                /**
                *
                * Previous object is dereferenced and new object
                * is saved.  New objects reference count is assumed to already
                * be incremented
                *
                * @author Mark Ditto
                *
                * @param object = object to assign to autodereference
                *
                * @return this
                **/
                AutoDereference<T>& operator=(
                        T *object
                        )
                {
                        T *o = m_object;

                        m_object = object;
                        derefObject(o);
                        return *this;
                };

                /**
                *
                * Previous object is dereferenced and new object
                * is saved.
                *
                * @author Mark Ditto
                *
                * @param object = object to assign to autodereference
                *
                * @return this
                **/
                AutoDereference<T>& operator=(
                        const AutoDereference<T> &object
                        )
                {
                        *this = refObject(*object);
                        return *this;
                };

                /**
                * * and ->
                *
                * @author Mark Ditto
                *
                * @return object pointer
                **/

                T* operator->() const
                {
                        return m_object;
                };

                T* operator*() const
                {
                        return m_object;
                };

                /**
                *
                * Determine if the AutoDereference has a value
                *
                * @author Mark Ditto
                *
                * @return true - if null object, false if value
                **/
                bool operator!() const
                {
                        return m_object == 0;
                };
                /**
                * ++
                *
                * Return an object pointer with it's reference count incremented by 1
                *
                * Caller owns a reference count
                *
                * @author Mark Ditto
                *
                * @return - object
                *
                **/
                T* operator++()
                {
                        return refObject(m_object);
                        return *this;
                };

                T* operator++(int)
                {
                        return refObject(m_object);
                        return *this;
                };

                /**
                * cast
                *
                * Cast the autodereference to it's class

                *
                * @return pointer to it's class
                *
                **/
                operator T*() const
                {
                        return m_object;
                };

                /**
                * comparison
                *
                * @author Mark Ditto
                *
                ***/
                bool operator== (const AutoDereference<T> &arg) const
                {
                        return (this == arg.m_object);
                };

                bool operator== (const T* arg) const
                {
                        return m_object == arg;
                };

                bool operator!= (const AutoDereference<T> &arg) const
                {
                        return (this != arg.m_object);
                }

                bool operator!= (const T* arg) const
                {
                        return !(m_object == arg);
                };

        private:

                /*************************************************/
                /******************* Variables *******************/
                /*************************************************/

                T* m_object;
};
#endif 

