#include <pthread.h>
#include <stdexcept>
#include <vector>
#include <queue>

typedef void* (*ThrFunc)(void*);
class Thread {
  
  ThrFunc m_tf;
  pthread_t m_tid;
  void *m_thrdata;
  public:
  Thread(ThrFunc l_tf):m_tf(l_tf),m_thrdata(NULL) {}
  Thread(ThrFunc l_tf,void *l_thrdata):m_tf(l_tf),m_thrdata(l_thrdata) {}

  void SetThreadFunc(ThrFunc l_tf) 
  {
    m_tf = l_tf;
  }

  pthread_t GetTid() const 
  {
    return m_tid;
  }

  void Run() throw(std::runtime_error)
  {
    if ( reinterpret_cast<ThrFunc>(NULL) != m_tf )  {
      pthread_create (&m_tid, NULL, m_tf, m_thrdata);
    } else {
      throw std::runtime_error("No thread function");
    }
  }

  void Join() {
    pthread_join(m_tid,NULL);
  }

  void Stop() {
    pthread_cancel(m_tid);
  }
};

class Mutex {
  friend class CondVar;

    pthread_mutex_t m_mtx;
  public:
    Mutex();
    void Lock();
    void Unlock();
    ~Mutex() 
    {
      pthread_mutex_destroy(&m_mtx);
    }
};

class CondVar {
    pthread_cond_t m_cnd;
    Mutex *m_asso_mtx;
  public:
    CondVar(Mutex *l_mtx): m_asso_mtx(l_mtx) 
    {
      //Do some error handling
      pthread_cond_init(&m_cnd,NULL);
    }

    ~CondVar()
    {
      pthread_cond_destroy(&m_cnd);
    }
    
    void CondSignal()
    {
      // wakeup only single thread
      pthread_cond_signal(&m_cnd);
    }

    void CondWait()
    {
      pthread_cond_wait (&m_cnd, &(m_asso_mtx->m_mtx));
    }
    
};


class Guard {
    Mutex *m_mtx;
  public:
    Guard(Mutex *l_mtx) {
      m_mtx = l_mtx;
      m_mtx->Lock();
    }
    ~Guard() {
      m_mtx->Unlock();
    } 
};

class ThreadPool {
  public:
    struct Task {
      ThrFunc t_func;
      void *t_data;
    };

  private:
    int m_nthr;
    int m_nbusythr;
    Mutex m_thrsync;
    CondVar m_thrcnd;
    CondVar m_waitcnd;
    std::vector<Thread*> m_thrds;
    std::queue<Task> m_tasks;

    static void* ParkThread(void *data);

  public:
    ThreadPool(int l_nthr = 3);
    void QueueTask(Task &l_task);
    void Wait(); //wait on threadpool
    void Stop(); 
    ~ThreadPool();
};

