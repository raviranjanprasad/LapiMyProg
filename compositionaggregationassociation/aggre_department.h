#ifndef _AGGRE_DEPARTMENT_H
#define _AGGRE_DEPARTMENT_H
#include <iostream>
#include <vector>
#include <string>
#include "aggreg_teacher.h"

using namespace std;

class Department
{
public:
	Department(std::string DepartmentName=""):m_Department_name(DepartmentName){cout<<"Department CTOR\n";}
	virtual ~Department();
	void Display() const;
	void ListTeachers() const;
	std::string getDepartmentName() const;
	void setDepartmentName(const std::string &DepartmentName);
	void allocateTeachers();
	std::vector<Teacher*> getTeachersList() const;
		
		
private:
	std::vector<Teacher*> m_vec_teacher;	
	std::string m_Department_name;
};
#endif /*_AGGRE_DEPARTMENT_H*/
