#include"comp_room.h"
Room::~Room()
{
	std::cout<<"Room DTOR\n";
}

void Room::DisplayRoom() const
{
	std::cout<<m_room_name << std::endl;
}

std::string Room::getRoomName() const
{
	return m_room_name;
}

void Room::setRoomName(const std::string &roomName)
{
	m_room_name = roomName;
}
