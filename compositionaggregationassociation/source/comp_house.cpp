#include"comp_house.h"

void House::Display() const
{
	cout<<"House Name is "<<m_house_name<<"\n";
	ShowRooms();
}

void House::ShowRooms() const
{
	cout<<"Total number of Rooms in "<<getHouseName() <<" are "<<m_vec_room.size()<<endl;
	cout<<"Name of the Rooms are" <<endl;
	cout<<"========================"<<"\n";
	for(unsigned i=0; i< m_vec_room.size(); i++)
	{
		m_vec_room[i].DisplayRoom();
	}; 
	cout<<"========================"<<"\n";

}

void House::setHouseName(const std::string &houseName)
{
	m_house_name = houseName;
}

std::string House::getHouseName() const
{
	return m_house_name;
}
void House::allocateRoomName()
{
	unsigned noOfRooms;
	

	cout<<"Enter the number of Rooms::";
	cin>>noOfRooms;
	cout<<endl;
    
	cout<<"Enter name of the Rooms::"<<endl;
	cin.ignore();
	for(unsigned i=1; i<=noOfRooms; i++)
	{
		std::string l_roomName;
		Room myHouseRoom;
		cout<<"Room"<<"["<<i<<"] Name::";
		std::getline(std::cin, l_roomName);
		myHouseRoom.setRoomName(l_roomName);
		m_vec_room.push_back(myHouseRoom);
	}
}

House::~House()
{
	std::cout<<"House DTOR Called\n";
}
