/*
Aggregation

To qualify as an aggregation, a whole object and its parts must have the following relationship:

The part (member) is part of the object (class)
The part (member) can belong to more than one object (class) at a time
The part (member) does not have its existence managed by the object (class)
The part (member) does not know about the existence of the object (class)

The part class is declared as a references or pointers that are used to 
point at objects that have been created outside the scope of the class.

Because these parts exist outside of the scope of the class, when the class
is destroyed, the pointer or reference member variable will be destroyed 
(but not deleted). Consequently, the parts themselves will still exist.
*/
#ifndef _TEACHER_H
#define _TEACHER_H
#include "common.h"

class Teacher
{
public:
    Teacher(std::string name="")
        : m_name(name)
    {
		std::cout<<"CTOR Teacher\n";
    }
	virtual ~Teacher();
 
    std::string getName() const;
	void setName(const std::string &name);
	void showTeacher() const;

private:
    std::string m_name;
};
#endif /* _TEACHER_H*/
