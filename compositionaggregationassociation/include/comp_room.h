#include<iostream>
#include<string>
/*
**Composition

To qualify as a composition, an object and a part must have the following relationship:

The part (member) is part of the object (class)
The part (member) can only belong to one object (class) at a time
The part (member) has its existence managed by the object (class)
The part (member) does not know about the existence of the object (class)

The part class should be a member variable of the Whole class.
e.g Room class should be a member varibale of the class Home.
*/
class Room
{
public:
	Room(std::string roomName=""):m_room_name(roomName)
	{
		std::cout<<"Room ctor\n";
	}
	void DisplayRoom()const;
	std::string getRoomName() const;
	void setRoomName(const std::string &roomName);
	virtual ~Room();
private:
	void setRoomName();
	std::string m_room_name;
};
