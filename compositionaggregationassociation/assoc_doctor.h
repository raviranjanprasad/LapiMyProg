/*
To qualify as an association, an object and another object must have the following relationship:

The associated object (member) is otherwise unrelated to the object (class)
The associated object (member) can belong to more than one object (class) at a time
The associated object (member) does not have its existence managed by the object (class)
The associated object (member) may or may not know about the existence of the object (class)
Unlike a composition or aggregation, where the part is a part of the whole object, in an association, the associated object is otherwise unrelated to the object. Just like an aggregation, the associated object can belong to multiple objects simultaneously, and isn’t managed by those objects. However, unlike an aggregation, where the relationship is always unidirectional, in an association, the relationship may be unidirectional or bidirectional (where the two objects are aware of each other).

The relationship between doctors and patients is a great example of an association. The doctor clearly has a relationship with his patients, but conceptually it’s not a part/whole (object composition) relationship. A doctor can see many patients in a day, and a patient can see many doctors (perhaps they want a second opinion, or they are visiting different types of doctors). Neither of the object’s lifespans are tied to the other.

We can say that association models as “uses-a” relationship. The doctor “uses” the patient (to earn income). The patient uses the doctor (for whatever health purposes they need).

Implementing associations

Because associations are a broad type of relationship, they can be implemented in many different ways. However, most often, associations are implemented using pointers, where the object points at the associated object.

In this example, we’ll implement a bi-directional Doctor/Patient relationship, since it makes sense for the Doctors to know who their Patients are, and vice-versa.

Composition vs aggregation vs association summary

Here’s a summary table to help you remember the difference between composition, aggregation, and association:

Property	                                Composition	                  Aggregation	            Association
Relationship type	                        Whole/part	                  Whole/part	            Otherwise unrelated
Members can belong to multiple classes	    No	                          Yes	                    Yes
Members existence managed by class	        Yes	                          No	                    No
Directionality	                            Unidirectional				  Unidirectional			Unidirectional or bidirectional
Relationship verb							Part-of						  Has-a	                    Uses-a
Example                                     House---Room                  Department---Teacher      Doctor---Patient.
*/
#ifndef _DOCTOR_
#define _DOCTOR_
#include<iostream>
#include<vector>
#include"assoc_paitent.h"

class Patient;

class Doctor
{
private:
	std::string m_name;
	std::vector<Patient *> m_patient;
 
public:
	Doctor(std::string name):
		m_name(name)
	{
	}
	void addPatient(Patient *pat);
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doc);
	std::string getName() const;
    
};
#endif /*_DOCTOR_*/
