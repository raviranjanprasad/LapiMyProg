#include<iostream>
#include<new>
#include<string>

using namespace std;

class Person{
    string m_name;
    string m_sssn;
    string m_dep;
    int m_age;
    double m_sal;

public:
    Person(string name="", string sssn="",string dep="", int age=0, double sal=0):m_name(name),m_sssn(),m_dep(dep),m_age(age),m_sal(sal){cout<<"*" <<endl;}
    void display(){ cout <<"Name=" << m_name <<endl;}
    ~Person(){ cout<<"Destructor called\n";}
        
};

int main(){
    Person *p = static_cast<Person*> (operator new(sizeof(Person)));
    cout <<"========================\n";
    new (p) Person("Ravi","123erty","Netbackup",28,30000000);
    p->display();
    p->~Person();
    cout <<"========================\n";
    new (p) Person("Neeharika","345iuy");
    p->display();
    p->~Person();
    cout <<"========================\n";
    new (p) Person("Archana");
    p->display();
    p->~Person();
    cout <<"========================\n";
    delete p;
}
