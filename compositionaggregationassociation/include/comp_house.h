#ifndef _COMP_HOUSE_H
#define _COMP_HOUSE_H
#include <iostream>
#include <vector>
#include <string>
#include "comp_room.h"

using namespace std;

class House
{
public:
	House(std::string houseName=""):m_house_name(houseName){cout<<"House CTOR\n";}
	virtual ~House();
	void Display() const;
	void ShowRooms() const;
	std::string getHouseName() const;
	void setHouseName(const std::string &houseName);
	void allocateRoomName();
		
private:
	std::vector<Room> m_vec_room;	
	std::string m_house_name;
};
#endif /*_COMP_HOUSE_H*/