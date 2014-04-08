#include<iostream>
#include<typeinfo>

using namespace std;

class Base{
 double m_bd;
 int m_bi;
public:
  Base(double d=0.0,int i=0):m_bd(d),m_bi(i){}
   //void Display(){cout <<"m_bd="<<m_bd<<"m_bi="<<m_bi<<endl;}
  virtual void Display(){cout <<"m_bd="<<m_bd<<"m_bi="<<m_bi<<endl;}
  // error: cannot dynamic_cast âb1âof type âass Base*âto type âass Drive*âsource type is not polymorphic)
  //~Base();
  // warning: dynamic_cast of âse b1âo âass Drive*âan never succeed
  //virtual ~Base();
  ~Base(){}
};

class Drive:public Base{
 double m_derd;
 int m_deri;
public:
 Drive(double d=0.0,int i=0):m_derd(d),m_deri(i){}
 void Display(){cout <<"m_derd="<<m_derd<<"m_deri="<<m_deri<<endl;}
 ~Drive(){}
};

class Unrelate{
 double m_unreld;
 int m_unreli;
public:
 Unrelate(double d=0.0,int i=0):m_unreld(d),m_unreli(i){}
 void Display(){cout <<"m_unreld="<<m_unreld<<"m_unreli="<<m_unreli<<endl;}

};

int main(int argc, char *argv[])
{
   Base *bptr;
   Drive *dptr;
   Base b1(10.20);
   Drive d1(40,60);

   //bptr = &d1;
   /*if(bptr = dynamic_cast<Base*>(&d1))
    cout <<"Of type Base" <<endl;
   else
    cout <<"Of type Derived" <<endl;

   bptr->Display();*/
  // warning: dynamic_cast of âse b1âo âass Drive*âan never succeed
  // m_derd=40m_deri=60
  // Segmentation fault (core dumped)
  //
  /*if(dptr = dynamic_cast<Drive*>(&b1))
    cout <<"Of Type Drive"  <<endl;
  else
    cout <<"Of Type Base" <<endl;*/
/*Of type Base
 * m_derd=40m_deri=60
 * Of Type Base
 * Segmentation fault (core dumped)*/




   //error: invalid conversion from âse*âo âive*âB
   //dptr = &b1;
   //m_bd=0m_bi=0
   //m_derd=-0.308517m_deri=-1076642088
   // dptr = (Drive*)&b1;
   //dptr->Display();
  
   /*dptr = static_cast<Drive*>(&b1);
   dptr->Display();*/

/*   Of type Base
m_derd=40m_deri=60
Of Type Base
m_bd=10.2m_bi=0*/

   //bptr = &d1;
   if(dptr = dynamic_cast<Drive*>(bptr))
    cout <<"Of Type Drive"  <<endl;
  else
    cout <<"Of Type Base" <<endl;
   
    dptr->Display();
/*
 * Of type Base
 * m_derd=40m_deri=60
 * Of Type Drive
 * m_derd=40m_deri=60
 *
 */

/*Without bptr= &d1 or
 * Typcasting of drive to base
 [ravi@localhost TypeCast]$ ./checkStaticCast
Of Type Base
Segmentation fault (core dumped)*/

   return 0;
}
