
#include "Common.h"

Mutex::Mutex()
{
  pthread_mutexattr_t attr;
  int error;

  error = pthread_mutexattr_init(&attr);
  if ( error ) {
    throw std::runtime_error("pthread_mutexattr_init failed");
  }

  error = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
  if ( error ) {
    throw std::runtime_error("pthread_mutexattr_settype failed");
  }
  
  error = pthread_mutex_init(&m_mtx, NULL);
  if ( error ) {
    throw std::runtime_error("pthread_mutex_init failed");
  }
  
  error = pthread_mutexattr_destroy(&attr);
  if ( error ) {
    throw std::runtime_error("pthread_mutexattr_destroy failed");
  }
}

void 
Mutex::Lock()
{
  int error = pthread_mutex_lock(&m_mtx);
  if ( error ) {
    throw std::runtime_error("pthread_mutex_lock failed");
  }

}

void 
Mutex::Unlock()
{
  int error = pthread_mutex_unlock(&m_mtx);
  if ( error ) {
    throw std::runtime_error("pthread_mutex_unlock failed");
  }
}

