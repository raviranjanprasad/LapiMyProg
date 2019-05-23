#include "aggreg_teacher.h"

std::string Teacher::getName() const
{
	return m_name;
}

void Teacher::setName(const std::string &name)
{
	m_name = name;
}

void Teacher::showTeacher() const
{
	std::cout<<"Teacher Name =" <<m_name<<std::endl;
}

Teacher::~Teacher()
{
	std::cout<<"DTOR Teacher" <<std::endl;
}
