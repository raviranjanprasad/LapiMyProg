#include<iostream>
#include<cstring>

using namespace std;

class Person{
public:
      Person(int age=0,char *name=""):m_age(age),m_name(new char[strlen(name) + 1]){
           strcpy(m_name,name);
      }
     
      Person(const Person &per){
      //Person(const Person *per){
            m_age = per.m_age;
            m_name = new char[strlen(per.m_name) + 1];
            strcpy(m_name,per.m_name);
            
            /*m_age = per->m_age;
            m_name =  new char[strlen(per->m_name) + 1];
            strcpy(m_name,per->m_name);*/
      }

      Person &operator=(const Person &per){
      //Person &operator=(const Person *per){
            if(this == &per)
               return *this;

            m_age = per.m_age;
            m_name = new char[strlen(per.m_name) + 1];
            strcpy(m_name,per.m_name);

            return *this;
      }

      friend ostream& operator<<(ostream &out,const Person &per);
      friend ostream& operator<<(ostream &out,const Person *per);

      ~Person(){
           delete [] m_name;
           cout <<"Destructor Called\n";
       }

private:
      int m_age;
      char *m_name;
};


ostream& operator<<(ostream &out,const Person &per){
          out<<"Name: " <<per.m_name<<endl;
          out<<"Age:  " <<per.m_age<<endl;
          return out;
      }
ostream& operator<<(ostream &out,const Person *per){
          out<<"Name: " <<per->m_name<<endl;
          out<<"Age:  " <<per->m_age<<endl;
          return out;
      }

int main(int argc, char *argv[]){
    Person *per1 = new Person(25,"Ravi");
    Person per2(28,"Pravin");

    /*Replacing reference with poiinter this will not work*/
    //Person per3(per1);    //Do not work for Reference
    //Person per3(&per1);   //Do not work for Reference
    Person per4(per2);

   /*For pointer this will wrok*/
   //Person per3(per1);
   //Person per4(&per2);

    cout<<per1<<endl;
    cout<<per2<<endl;
    //cout<<per3<<endl;
    cout<<per4<<endl;

    return 0;
}
