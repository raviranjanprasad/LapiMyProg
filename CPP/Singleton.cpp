#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;


/*Lock Class to prevent creation of object in multiple threads try to create object*/
class Lock{
public:
      Lock(){}
      ~Lock(){}
      void InitLock();      ///Initialize Mutex variable
      void AcquireLock();   //Aquire Lock 
      void ReleaseLock();   //Release Lock
private:
      pthread_mutex_t work_mutex;
};

void Lock::InitLock(){
     pthread_mutex_init(&work_mutex,NULL);
}

void Lock::AcquireLock(){
      cout<<"Taking the lock before creating Object"<<endl;
      pthread_mutex_lock(&work_mutex);
}

void Lock::ReleaseLock(){
      cout<<"Realeasing the Mutex Lock" <<endl;
       pthread_mutex_unlock(&work_mutex);
}

/*Singleton Class restrict to  create only one instance*/
class Singleton{
public:
      static Singleton *getInstance();
      void Display();
private:
      Singleton(){}
      Singleton(const Singleton &obj);
      Singleton &operator=(const Singleton &obj);
      static Singleton *instance;
      static Lock lock;
};

Singleton *Singleton::instance = 0;
Lock Singleton::lock;
Singleton *Singleton::getInstance(){

     if(!instance){
         lock.AcquireLock();
         instance = new Singleton();
         lock.ReleaseLock();
         cout<<"First Instance" <<endl;
         return instance;
     }
     else{
         cout <<"Previous Instance" <<endl;
         return instance;
     }
}

void Singleton::Display(){
   cout <<"Hello World" <<endl;
}

int main()
{
     Singleton *obj1 = Singleton::getInstance();
     if(obj1)
       obj1->Display();
     //Singleton obj2(&obj1);
     Singleton *obj2 = Singleton::getInstance();
     if(obj2)
       obj2->Display();

     if(obj1 == obj2)
       cout <<"Samae Instance\n";
     delete obj1;
     return 0;
}
