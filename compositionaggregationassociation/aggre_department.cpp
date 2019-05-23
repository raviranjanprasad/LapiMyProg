#include"aggre_department.h"

void Department::Display() const
{
	cout<<"Department Name is "<<m_Department_name<<"\n";
	ListTeachers();
}

void Department::ListTeachers() const
{
	cout<<"Total number of Teachers in department "<<getDepartmentName() <<" are "<<m_vec_teacher.size()<<endl;
	cout<<"Name of the Teachers are" <<endl;
	cout<<"========================"<<"\n";
	for(unsigned i=0; i< m_vec_teacher.size(); i++)
	{
		m_vec_teacher[i]->showTeacher();
	}; 
	cout<<"========================"<<"\n";

}

void Department::setDepartmentName(const std::string &DepartmentName)
{
	m_Department_name = DepartmentName;
}

std::string Department::getDepartmentName() const
{
	return m_Department_name;
}
void Department::allocateTeachers()
{
	unsigned noOfTeachers;
	

	cout<<"Enter the number of Teacher::";
	cin>>noOfTeachers;
	cout<<endl;
    
	cout<<"Enter name of the Teacher::"<<endl;
	cin.ignore();
	for(unsigned i=1; i<=noOfTeachers; i++)
	{
		std::string l_teacherName;
		Teacher *depTeacher= new Teacher(l_teacherName);
		cout<<"teacher"<<"["<<i<<"] Name::";
		std::getline(std::cin, l_teacherName);
		depTeacher->setName(l_teacherName);
		m_vec_teacher.push_back(depTeacher);
		//delete depTeacher;
	}
}

std::vector<Teacher*> Department::getTeachersList() const
{
	return m_vec_teacher;
}

Department::~Department()
{
	std::cout<<"Department DTOR Called\n";
}
