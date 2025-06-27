#include<iostream>
#include<string.h>
#include<list>
#include<map>

using namespace std;
class Employee;
class Teacher;
class Manager;
class Subject;
class Schedule;
class Class;
class Room;

class Employee{
private:
	string name;
public:
	~Employee(){}
	Employee(string name);

	void setName(string name);

	string getName();

	void display();
};

class Teacher:public Employee{
private:
	string faculty;
	Schedule* schedule;
public:
	~Teacher(){}
	Teacher(string name,string faculty);

	void setFaculty(string faculty);

	string getFaculty();
	Schedule* getSchedule();

	void display();

};

class Manager:public Employee{
private:
public:
	~Manager(){}
	Manager(string name);

	void display();
};

class Subject{
private:
	string ID;
	string name;
public:
	~Subject(){}
	Subject(string ID,string name);

	void setID(string ID);
	void setName(string name);

	string getID();
	string getName();

	void display();
};

class Room{
private:
	string name;
	string size;
public:
	~Room(){}
	Room(string name,string size);

	void setName(string name);
	void setSize(string size);

	string getName();
	string getSize();

	void display();
};

class Class{
private:
	string time;
	Room* room;
	Subject* subject;
public:
	~Class(){}
	Class(string time,Room* room,Subject* subject);

	void setTime(string time);
	void setRoom(Room* room);
	void setSubject(Subject* subject);

	string getTime();
	Room* getRoom();
	Subject* getSubject();

	void display();
};

class Schedule{
private:
	list<Class*> classes;
public:
	~Schedule(){
		for(auto it : classes){
			delete it;
		}
	}
	void addClass(Subject* subject,Room* room,string time);

	void displayClasses();
};


//Class Employee
Employee::Employee(string name) {
    this->setName(name);
}

void Employee::setName(string name) {
    this->name = name;
}

string Employee::getName() {
    return this->name;
}

void Employee::display() {
    cout << "Name: " << this->getName() << '\n';
}



//Class Teacher
Teacher::Teacher(string name,string faculty):Employee(name) {
    this->setFaculty(faculty);
    this->schedule =  new Schedule();
}

void Teacher::setFaculty(string faculty) {
    this->faculty = faculty;
}

string Teacher::getFaculty() {
    return this->faculty;
}

Schedule* Teacher::getSchedule(){
	return this->schedule;
}

void Teacher::display() {
	Employee::display();
    cout << "Faculty: " << this->getFaculty() << '\n';
}


//Class Manager
Manager::Manager(string name):Employee(name){}

void Manager::display(){
	Employee::display();
}



//Class Subject
Subject::Subject(string ID, string name) {
    this->setID(ID);
    this->setName(name);
}

void Subject::setID(string ID) {
    this->ID = ID;
}

void Subject::setName(string name) {
    this->name = name;
}

string Subject::getID() {
    return this->ID;
}

string Subject::getName() {
    return this->name;
}

void Subject::display() {
    cout << "ID: " << this->getID() << '\n';
    cout << "Name: " << this->getName() << '\n';
}



//Class Room
Room::Room(string name, string size) {
    this->setName(name);
    this->setSize(size);
}

void Room::setName(string name) {
    this->name = name;
}

void Room::setSize(string size) {
    this->size = size;
}

string Room::getName() {
    return this->name;
}

string Room::getSize() {
    return this->size;
}

void Room::display() {
    cout << "Name: " << this->getName() << '\n';
    cout << "Size: " << this->getSize() << '\n';
}



//Class Class
Class::Class(string time,Room* room,Subject* subject) {
    this->setTime(time);
    this->setRoom(room);
    this->setSubject(subject);
}

void Class::setTime(string time) {
    this->time = time;
}

void Class::setRoom(Room* room){
	this->room = room;
}

void Class::setSubject(Subject* subject){
	this->subject = subject;
}

string Class::getTime() {
    return this->time;
}

Room* Class::getRoom(){
	return this->room;
}

Subject* Class::getSubject(){
	return this->subject;
}

void Class::display() {
    cout << "Time: " << this->getTime() << '\n';
    this->getRoom()->display();
    this->getSubject()->display();
}


//Class Schedule
void Schedule::addClass(Subject* subject,Room* room,string time){
	Class* tmp = new Class(time,room,subject);
	this->classes.push_back(tmp);
}

void Schedule::displayClasses(){
	int i=0;
	for(auto it : this->classes){
		cout<<'#'<<++i<<endl;
		it->display();
	}
	cout<<endl;
}

int main(){
	Teacher* person = new Teacher("Alice","Toan - Tin Hoc");
	Subject* dsa = new Subject("MTH10405","DSA");
	Subject* oop = new Subject("MTH10407","OOP");
	Room* room = new Room("C204","40");
	person->getSchedule()->addClass(dsa,room,"2023-2024-HK2-Tue");
	person->getSchedule()->addClass(oop,room,"2023-2024-HK2-Wed");
	person->getSchedule()->displayClasses();
	delete person;
	return 0;
}