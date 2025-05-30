#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;

class Floor;
class Room;
class RestRoom;
class CouncilRoom;
class StudyRoom;
class Customer;

class Floor{
private:
	int number;
	list<Room*> rooms;
public:
	Floor(int number);

	//Setter & Getter
	void setNumber(int number);
	void setRoom(Room* room);

	int getNumber();
	list<Room*> getRoom();

	//Other Methods
	void display();
};

class Room{
private:
	int number;
	Floor* floor;
	Customer* customer;
public:
	Room(int number);
	//Setter & Getter
	void setNumber(int number);
	void setFloor(Floor* floor);
	void setCustomer(Customer* customer);

	int getNumber();
	Floor* getFloor();
	Customer* getCustomer();

	//Other Methods
	virtual void display();
	void displayStudyRoom();

};

class RestRoom:public Room{
public:
	RestRoom(int number);
	void display();
};

class StudyRoom:public Room{
private:
	CouncilRoom* councilRoom;
public:
	StudyRoom(int number);
	//Setter & Getter
	void setCouncilRoom(CouncilRoom* councilRoom);

	CouncilRoom* getCouncilRoom();
	//Other Methods

	void display();
};

class CouncilRoom:public Room{
private:
	string name;
	list<StudyRoom*> studyRooms;
public:
	CouncilRoom(int number,string name);
	//Setter & Getter
	void setName(string name);
	void setStudyRoom(StudyRoom* studyRoom);

	string getName();
	list<StudyRoom*> getStudyRoom();

	//Other Methods
	void display();
	void displayStudyRoom();
};

class Customer{
private:
	string name;
	string ID;
	list<Room*> rooms;
public:
	Customer(string name,string ID);
	//Setter & Getter
	void setName(string name);
	void setID(string ID);

	string getName();
	string getID();
	list<Room*> getRoom();

	//Other Methods
	void display();
	void bookRoom(Room* room);
	void displayRoom();
};


//Class Floor
Floor::Floor(int number) {
    this->setNumber(number);
}

void Floor::setNumber(int number) {
    this->number = number;
}

void Floor::setRoom(Room* room){
	this->rooms.push_back(room);
	room->setFloor(this);
}

int Floor::getNumber() {
    return this->number;
}

list<Room*> Floor::getRoom(){
	return rooms;
}

void Floor::display(){
	cout<<"Floor "<< this->getNumber() <<'\n';
}


//Class Room
Room::Room(int number) {
    this->setNumber(number);
}

void Room::setNumber(int number) {
    this->number = number;
}

void Room::setFloor(Floor* floor){
	this->floor  = floor;
}

void Room::setCustomer(Customer* customer){
	this->customer = customer;
}

int Room::getNumber() {
    return this->number;
}

Floor* Room::getFloor(){
	return this->floor;
}

Customer* Room::getCustomer(){
	return this->customer;
}

void Room::display(){
	cout<<"Room "<< this->getNumber() <<'\n';
}


//Class RestRoom
RestRoom::RestRoom(int number):Room(number){}

void RestRoom::display(){
	Room::display();
}

//Class StudyRoom
StudyRoom::StudyRoom(int number):Room(number){}

void StudyRoom::setCouncilRoom(CouncilRoom* councilRoom){
	this->councilRoom = councilRoom;
}

CouncilRoom* StudyRoom::getCouncilRoom(){
	return this->councilRoom;
}

void StudyRoom::display(){
	Room::display();
}


//Class CouncilRoom
CouncilRoom::CouncilRoom(int number,string name) : Room(number){
    this->setName(name);
}

void CouncilRoom::setName(string name) {
    this->name = name;
}

void CouncilRoom::setStudyRoom(StudyRoom* studyRoom){
	this->studyRooms.push_back(studyRoom);
	studyRoom->setCouncilRoom(this);
}

string CouncilRoom::getName() {
    return this->name;
}

list<StudyRoom*> CouncilRoom::getStudyRoom(){
	return studyRooms;
}

void CouncilRoom::display(){
	Room::display();
	cout<<"Name of Council Room : "<< this->getName() <<  '\n';
}

void CouncilRoom::displayStudyRoom(){
	int i=0;
	cout<<"List of Study Rooms is  \n";
	for(auto it : this->studyRooms){
		cout<<'#'<<++i<<'\n';
		it->display();
	}
	cout<<'\n';
}




//Class Customer
Customer::Customer(string name, string ID) {
    this->setName(name);
    this->setID(ID);
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setID(string ID) {
    this->ID = ID;
}

string Customer::getName() {
    return this->name;
}

string Customer::getID() {
    return this->ID;
}

list<Room*> Customer::getRoom(){
	return rooms;
}

void Customer::display(){
	cout<<"Name Customer : " << this->getName() <<'\n';
	cout<<"ID : " << this->getID() <<'\n';
}

void Customer::bookRoom(Room* room){
	this->rooms.push_back(room);
	room->setCustomer(this);
}

void Customer::displayRoom(){
	int i=0;
	for(auto it : this->rooms){
		cout<<++i<<')'<<'\n';
		it->display();
	}
	cout<<"\n\n";
}
//int main(){
//	Customer* cus1 =  new Customer("Hao","123");
//	CouncilRoom* p = new CouncilRoom(302,"Hop");
//	RestRoom* r = new RestRoom(502);
//	StudyRoom* s1 = new StudyRoom(321);
//	StudyRoom* s2 = new StudyRoom(311);
//	p->setStudyRoom(s1); 
//	p->setStudyRoom(s2);
//	cus1->bookRoom(r);
//	cus1->bookRoom(p);
//	cout<<"Display Rooms booked by customer "<< cus1->getName() << '\n';
//	cus1->displayRoom();
//	cout<<"Rooms in an Council Room\n";
//	p->displayStudyRoom();
//	delete cus1;
//	delete p;
//	delete r;
//	delete s1;
//	delete s2;
//	return 0;
//}