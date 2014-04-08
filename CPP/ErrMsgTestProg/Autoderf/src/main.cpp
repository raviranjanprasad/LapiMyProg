/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2014 04:52:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ravi Prasad (Senior software Engineer), ravi_prasad@symantec.com
 *   Organization:  Symantec Software
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include <sstream>
#include "autodref.h"

using namespace std;
class Base :public ostringstream{
        public:
                Base() {}//cout <<"Base constructoru\n";}
                virtual ~Base() {}//cout <<"Base Destructor\n";}
                void NextParamUtf8(char const * const p){
                *this << p;
                cout << "this pointer called\n";
                //cout << p <<endl;
        }

};

class StatusMsgBase: public Base,public virtual NCFRefCounted{
        string  m_test;
        public:
        StatusMsgBase(string test=""):m_test(test){}//cout<<"StatusMsgBase Constructor\n";}
        ~StatusMsgBase(){}//cout <<"StatusMsgBase Destructoru\n";}

        friend StatusMsgBase& operator<<(StatusMsgBase& msg, const string &str);
};

inline StatusMsgBase& operator<<(StatusMsgBase& msg, const string &str)
{
        msg.NextParamUtf8(str.c_str());
        //cout <<"StatusMsgBase Operator overloading called\n";
        return msg;
}


class StatusMsg: public StatusMsgBase{
        string m_der;
        int m_severity;
        bool m_nbuStatus;
        public:
        StatusMsg(string bs="Base string not provided",string de="",int severity=0,bool nbu=true)
            :StatusMsgBase(bs),
             m_der(de),
            m_severity(severity),
            m_nbuStatus(nbu){}//cout <<"StatusMsg Construcntor\n";}
        ~StatusMsg(){}//cout <<"StatusMsg Destructor\n";}
        
        string getder() const{
            return m_der;
        }
        int getSeverity() const{
            return m_severity;
        }

        bool getNbuServerStatus() const {
            return m_nbuStatus;
        }
         //friend std::ostream& operator<<( std::ostream &os, const StatusMsg &ref);

        friend StatusMsg& operator<<(StatusMsg& msg, const string &str);

};

inline StatusMsg& operator<<(StatusMsg& msg, const string &str)
{
                msg.NextParamUtf8(str.c_str());
                cout <<"StatusMsg Operator overloading called\n";
                        return msg;
}


//use of **msg<<s is only visible if you put "ref->str()" in the buffer.
//ref->str() keep the string pushed to msg object to display.
static void formatMessage(
        string &buffer,
        const StatusMsgBase &refbase
        )
     {
        const StatusMsg *ref = dynamic_cast<const StatusMsg *>(&refbase);    
        ostringstream b;
        b << buffer.c_str() << "Derive string="<< ref->getder()<<", nbu status = " << ref->getNbuServerStatus()
            << ", severity = " << ref->getSeverity()<< "  " <<ref->str();
     
     
        buffer = b.str();
     }
    

//No need to overload the operator << for base and drived class, keep it global and pass the base
//pointer or ref to access both the base and derive member variables and methods.
inline ostream& operator<<( ostream &os, const StatusMsgBase &ref)
     {
        cout <<"\nostream called with string buffer\n";
        string buffer;
        formatMessage(buffer, *dynamic_cast<const StatusMsg *>(&ref));
        os << buffer.c_str();
        
        return os;
     }

//Invoking a dervied class with base class pointer.
StatusMsgBase *testFun(const string s){

        AutoDereference<StatusMsgBase> msg;
        msg = new StatusMsg("Ravi","Prasad",123903,true);
        **msg << s;
        //cout <<**msg<<endl;
        
        return ++msg;
}

int main(){


        //Test 1
        string sd1 = "Learn to live";
        StatusMsgBase *ob = testFun(sd1);
        cout <<"testFun() called\n";
        cout << *ob << endl;

        //Test 2
        string sd2="Live better";
        AutoDereference<StatusMsgBase> msg;
        msg = new StatusMsg("Base","Derived",5,true);
        **msg << sd2;

        cout <<**msg<<endl;
        ++msg;

        return 0;
}


