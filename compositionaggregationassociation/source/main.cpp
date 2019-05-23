#include "comp_house.h"
#include "aggre_department.h"
#include "assoc_paitent.h"
#include "assoc_doctor.h"


int main(int argc, char *argv[])
{
	/*Composition Calling client*/
	/*House myHouse("Ranjan Niwas");
	myHouse.allocateRoomName();
	myHouse.Display();*/

	/*Aggregation Calling client*/
	/*Department univDepart("Priston Computer Department");
	univDepart.allocateTeachers();
	univDepart.Display();*/
	
	/*As Department and Teacher is in aggreation 
	  Relationship, Teacher life cycle is not controlled
	  by the Department. Hence the destorying of Department
	  is not supposed to destory the teacher. So it is requrie
	  to delete the teacher object explicitly.*/
	/*std::vector<Teacher*> depTeachers = univDepart.getTeachersList();
	for(unsigned i=0; i<depTeachers.size(); i++)
	{
		delete depTeachers[i];
	}*/

	/*Association calling client.*/
	// Create a Patient outside the scope of the Doctor
	Patient *p1 = new Patient("Dave");
	Patient *p2 = new Patient("Frank");
	Patient *p3 = new Patient("Betsy");
 
	Doctor *d1 = new Doctor("James");
	Doctor *d2 = new Doctor("Scott");
 
	d1->addPatient(p1);
 
	d2->addPatient(p1);
	d2->addPatient(p3);
 
	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';
	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';
 
	/*As both doctor and patient are in the
	association relationship both need to 
	deleted by third party.*/
	delete p1;
	delete p2;
	delete p3;
	
	delete d1;
	delete d2;
 
	return 0;
}
