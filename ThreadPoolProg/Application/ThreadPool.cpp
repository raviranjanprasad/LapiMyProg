#include "Common.h"

void* ThreadPool::ParkThread(void *data) 
{
  ThreadPool *l_thrpool = reinterpret_cast<ThreadPool *>(data);
  std::queue<Task> &l_tasks = l_thrpool->m_tasks;
  Mutex &l_thrsync   = l_thrpool->m_thrsync;
  CondVar &l_thrcnd  = l_thrpool->m_thrcnd;
  CondVar &l_waitcnd = l_thrpool->m_waitcnd;
  int &l_nbusythr = l_thrpool->m_nbusythr;
 
  for(;;)
  {
    Task l_current;
    {
      Guard g(&l_thrsync);
      while ( l_tasks.empty() ) //No task, Park the thread 
      { 
        if(l_nbusythr == 0) {
          l_waitcnd.CondSignal();
        }
        l_thrcnd.CondWait();
      }
      
      l_current = l_tasks.front();
      l_tasks.pop();
      ++l_nbusythr;
    }
    l_current.t_func(l_current.t_data);
    {
      Guard g(&l_thrsync);
      --l_nbusythr;
    }
  }
}

ThreadPool::ThreadPool(int l_nthr):m_nthr(l_nthr),
                                     m_nbusythr(0),
                                       m_thrcnd(&m_thrsync),
                                         m_waitcnd(&m_thrsync) 
{
  for ( int kount = 0; kount < m_nthr; kount++) 
  {
    Thread *l_thr = new Thread(ParkThread,this);
    m_thrds.push_back(l_thr);
    l_thr->Run();
  }
}

void ThreadPool::QueueTask(Task &l_task) 
{
  Guard g(&m_thrsync);
  m_tasks.push(l_task);
  m_thrcnd.CondSignal();
}

void ThreadPool::Wait() 
{
  // Before acquiring lock ckeck whether the thread calling ThreadPool::Wait
  // belongs to the threadpool itself.Can't let that happen.
 
  for ( int ndx = 0; ndx < m_nthr; ndx++ )
  {
    if (  pthread_equal( m_thrds[ndx]->GetTid(), pthread_self()) ) {
      // threadpool thread calling ThreadPool::Wait
      return; //can throw error here
    }
  } 
  
  Guard g(&m_thrsync);
  while ( m_nbusythr ) 
  {
    m_waitcnd.CondWait();
  }
}

void ThreadPool::Stop() 
{
 // stop thread pool
  for ( int ndx = 0; ndx < m_nthr; ndx++ )
  {
    if (  pthread_equal( m_thrds[ndx]->GetTid(), pthread_self()) ) {
      // threadpool thread calling ThreadPool::Stop
      return; //can throw error here
    }
  } 

  for ( int ndx = 0; ndx < m_nthr; ndx++ )
  {
    pthread_cancel(m_thrds[ndx]->GetTid());
    pthread_join(m_thrds[ndx]->GetTid(),NULL);
  } 
}

ThreadPool::~ThreadPool()
{
  for ( int ndx = 0; ndx < m_nthr; ndx++ )
  {
    pthread_cancel(m_thrds[ndx]->GetTid());
    pthread_join(m_thrds[ndx]->GetTid(),NULL);
    delete m_thrds[ndx];
  } 

  for ( int kount = 0; kount < m_nthr; kount++) 
  {
    m_thrds.pop_back();
  }
}

