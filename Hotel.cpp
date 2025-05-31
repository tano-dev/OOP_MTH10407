/*
Một khách sạn bao gồm nhiều tầng. Mỗi tầng được đánh số như 1, 2, 3, ... Mỗi tầng có nhiều phòng. Phòng được đánh số như 201 (phòng số 01 ở tầng 2). Phòng được chia nhiều loại: phòng nghỉ, phòng hội nghị, phòng học. Phòng hội nghị có thể có nhiều phòng học. Phòng hội nghị có tên riêng, ví dụ Phòng hội nghị "Hoàng Sa".

Khách hàng có thể đặt phòng của khách sạn. Khách hàng có các thông tin về tên, CCCD.

Chương trình cần quản lý các thông tin sau:
Các tầng của khách sạn.
Các phòng của một tầng.
Khách hàng và các phòng mà khách hàng đặt.

Hiển thị thông tin các phòng mà khách hàng đã đặt. Trong trường hợp phòng hội nghị, hiển thị các phòng học có trong phòng hội nghị nếu có.
*/
#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;

class Hotel;
class Floor;
class Room;
class RestRoom;
class StudyRoom;
class ConferenceRoom;
class Customer;

class Hotel {
private:
	string name;
	map<string, Floor*> floors;
	map<string, Customer*> customers;
public:
	Hotel(string name);
	void setName(string name);
	string getName();
	void addFloor(Floor* floor);
	void addCustomer(Customer* customer);
	void display();
};
class Customer {
private:
	string name;
	string cccd;
	list<Room*> rooms;
public:
	Customer(string name, string cccd);
	void setName(string name);
	void setCccd(string cccd);
	string getName();
	string getCccd();
	list<Room*> getRooms();
	void bookRoom(Room* room);
	void display();
	void displayRooms();
};
class Floor {
private:
	string number;
	list<Room*> rooms;
public:
	Floor(string number);
	void setNumber(string number);
	string getNumber();
	void addRoom(Room* room);
	list<Room*> getRooms();
	virtual void display();
};
class Room {
private:
	string number;
	Customer* customer;
	Floor* floor;
public:
	Room(string number);
	void setNumber(string number);
	void setCustomer(Customer* customer);
	void setFloor(Floor* floor);
	string getNumber();
	Floor* getFloor();
	Customer* getCustomer();
	virtual void display();
};
class RestRoom : public Room {
public:
	RestRoom(string number);
	void display();
};
class StudyRoom : public Room {
private:
	ConferenceRoom* conferenceRoom = nullptr;
public:
	StudyRoom(string number);
	void setConferenceRoom(ConferenceRoom* conferenceRoom);
	virtual void display();
};
class ConferenceRoom : public Room {
private:
	string name;
	list<StudyRoom*> studyRooms;
public:
	ConferenceRoom(string number, string name);
	void setName(string name);
	void addStudyRoom(StudyRoom* studyRoom);
	string getName();
	void display();
};
//Hotel

Hotel::Hotel(string name) {
	this->setName(name);
}
void Hotel::setName(string name) {
	this->name = name;
}
string Hotel::getName() {
	return this->name;
}
void Hotel::addFloor(Floor* floor) {
	this->floors[floor->getNumber()] = floor;
}
void Hotel::addCustomer(Customer* customer) {
	this->customers[customer->getCccd()] = customer;
}
void Hotel::display() {
	cout << "Hotel Name: " << this->getName() << endl;
	cout << "Floors: " << endl;
	for (auto i : this->floors) {
		i.second->display();
	}
	cout << "Customers: " << endl;
	for (auto i : this->customers) {
		i.second->display();
	}
}
//Customer
Customer::Customer(string name, string cccd) {
	this->setName(name);
	this->setCccd(cccd);
}
void Customer::setName(string name) {
	this->name = name;
}
void Customer::setCccd(string cccd) {
	this->cccd = cccd;
}
string Customer::getName() {
	return this->name;
}
string Customer::getCccd() {
	return this->cccd;
}
list<Room*> Customer::getRooms() {
	return this->rooms;
}
void Customer::bookRoom(Room* room) {
	if (room->getCustomer() != nullptr) return;
	this->rooms.push_back(room);
	room->setCustomer(this);
}
void Customer::display() {
	cout << "Customer Name: " << this->getName() << endl;
	cout << "CCCD: " << this->getCccd() << endl;
}
void Customer::displayRooms() {
	cout << "Rooms booked by " << this->getName() << ":" << endl;
	for (auto i : this->rooms) {
		i->display();
	}
}
//Floor
Floor::Floor(string number) {
	this->setNumber(number);
}
void Floor::setNumber(string number) {
	this->number = number;
}
string Floor::getNumber() {
	return this->number;
}
void Floor::addRoom(Room* room) {
	this->rooms.push_back(room);
	room->setFloor(this);
}
list<Room*> Floor::getRooms() {
	return this->rooms;
}
void Floor::display() {
	cout << "Floor Number: " << this->getNumber() << endl;
	for (auto i : this->rooms) {
		i->display();
	}
}
//Room
Room::Room(string number){
	this->setNumber(number);
}
void Room::setNumber(string number) {
	this->number = number;
}
void Room::setCustomer(Customer* customer) {
	this->customer = customer;
}
void Room::setFloor(Floor* floor) {
	this->floor = floor;
}
string Room::getNumber() {
	return this->number;
}
Customer* Room::getCustomer() {
	return this->customer;
}
Floor* Room::getFloor() {
	return this->floor;
}
void Room::display() {
	cout << "  -No: " << this->getFloor()->getNumber() << this->getNumber() << endl;
}
//RestRoom
RestRoom::RestRoom(string number) :Room(number) {}
void RestRoom::display() {
	cout << "+ Rest Room: " << endl;
	Room::display();
}
//StudyRoom
StudyRoom::StudyRoom(string number) : Room(number) {}
void StudyRoom::setConferenceRoom(ConferenceRoom* conferenceRoom) {
	this->conferenceRoom = conferenceRoom;
}
void StudyRoom::display() {
	cout << "   +Study Room: "<< this->getFloor()->getNumber() << this->getNumber() << endl;
}
//ConferenceRoom
ConferenceRoom::ConferenceRoom(string number, string name) : Room(number) {
	this->setName(name);
}
void ConferenceRoom::setName(string name) {
	this->name = name;
}
void ConferenceRoom::addStudyRoom(StudyRoom* studyRoom) {
	studyRoom->setConferenceRoom(this);
	studyRoom->setFloor(this->getFloor());
	studyRoom->setCustomer(this->getCustomer());
	this->studyRooms.push_back(studyRoom);
}
string ConferenceRoom::getName() {
	return this->name;
}
void ConferenceRoom::display() {
	cout << "+ Conference Room " << this->getName() <<":" << endl;
	Room::display();
		cout << "  -Contains Study Rooms: " << endl;
		for (auto i : this->studyRooms) {
			i->display();
		}
}


//int main() {
//	Hotel* hotel = new Hotel("Grand Hotel");
//
//	Floor* floor1 = new Floor("1");
//	Floor* floor2 = new Floor("2");
//
//	RestRoom* restRoom1 = new RestRoom("01");
//	RestRoom* restRoom2 = new RestRoom("02");
//
//	StudyRoom* studyRoom1 = new StudyRoom("01");
//	StudyRoom* studyRoom2 = new StudyRoom("02");
//
//	ConferenceRoom* conferenceRoom1 = new ConferenceRoom("01", "Lac Da");
//
//
//	floor1->addRoom(restRoom1);
//	floor1->addRoom(restRoom2);
//	floor2->addRoom(conferenceRoom1);
//	conferenceRoom1->addStudyRoom(studyRoom1);
//	conferenceRoom1->addStudyRoom(studyRoom2);
//	hotel->addFloor(floor1);
//	hotel->addFloor(floor2);
//
//	Customer* customer1 = new Customer("Alice", "123456789");
//	customer1->bookRoom(restRoom1);
//	customer1->bookRoom(conferenceRoom1);
//
//	hotel->addCustomer(customer1);
//
//	hotel->display();
//	customer1->displayRooms();
//
//	delete hotel;
//	delete floor1;
//	delete floor2;
//	delete restRoom1;
//	delete restRoom2;
//	delete studyRoom1;
//	delete studyRoom2;
//	delete conferenceRoom1;
//	return 0;
//}