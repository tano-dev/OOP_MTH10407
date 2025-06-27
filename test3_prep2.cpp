/*
Xây dựng một chương trình C++ để quản lý thời khóa biểu giảng dạy của một giảng viên.

Một nhân viên trong trường học có thuộc tính là tên. Nhân viên có các loại như giáo viên, quản lý. Giáo viên có thuộc tính là khoa mà người đó đang giảng dạy.

Một môn học gồm có mã và tên môn học.

Thời khóa biểu của một giáo viên bao gồm nhiều lớp học. Lớp học có thời gian học, phòng học và của một môn học nào đó. Phòng học có tên và sức chứa.

Chương trình chính phải làm các chức năng sau:

• Tạo 1 giáo viên có tên là Alice thuộc khoa Toán - Tin học.
• Tạo 1 môn học có mã MTH10405, tên là “DSA”.
• Tạo 1 môn học có mã MTH10407, tên là “OOP”.
• Tạo 1 phòng học có tên C204, sức chứa là 40.
• Thêm 1 lớp học vào thời khóa biểu của Alice có các thông tin sau: của môn học đầu tiên, ở phòng học trên, và thời gian học là 2023-2024-HK2-Tue.
• Thêm 1 lớp học vào thời khóa biểu của Alice có các thông tin sau: của môn học thứ hai, ở phòng học trên, và thời gian học là 2023-2024-HK2-Wed.
• In thời khóa biểu của giáo viên ở trên.
*/
#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;

class Staff;
class Lecturer;
class Manager;
class Subject;
class Schedule;
class Classroom;
class Room;

class Staff {
private:
	string name;
public:
	Staff(string name);
	void setName(string name);
	string getName();
	virtual void display();
	virtual ~Staff() {}
};

class Lecturer : public Staff {
private:
	string faculty;
	Schedule* sche;
public:
	Lecturer(string name, string faculty);
	void setFaculty(string faculty);
	string getFaculty();
	Schedule* getSchedule();
	void display();
	~Lecturer();  // chỉ khai báo
};

class Manager : public Staff {
public:
	Manager(string name);
	void display();
	~Manager() {}
};

class Subject {
private:
	string ID;
	string name;
public:
	Subject(string ID, string name);
	void setID(string ID);
	void setName(string name);
	string getID();
	string getName();
	void display();
	~Subject() {}
};

class Room {
private:
	string name;
	int size;
public:
	Room(string name, int size);
	void setName(string name);
	void setSize(int size);
	string getName();
	int getSize();
	void display();
	~Room() {}
};

class Schedule {
private:
	list<Classroom*> classrooms;
public:
	Schedule();
	void addClassroom(Classroom* classroom);
	void display();
	~Schedule();
};

class Classroom {
private:
	string time;
	Room* room;
	Subject* subject;
public:
	Classroom(string time, Room* room, Subject* subject);
	void setTime(string time);
	void setRoom(Room* room);
	void setSubject(Subject* subject);
	string getTime();
	Room* getRoom();
	Subject* getSubject();
	void display();
	~Classroom() {}
};

//Staff 
Staff::Staff(string name) {
	this->setName(name);
}
void Staff::setName(string name) {
	this->name = name;
}
string Staff::getName() {
	return this->name;
}
void Staff::display() {
	cout << "Name: " << this->getName() << endl;
}
//Lecturer
Lecturer::Lecturer(string name, string faculty) : Staff(name) {
	this->setFaculty(faculty);
	this->sche = new Schedule();
}
void Lecturer::setFaculty(string faculty) {
	this->faculty = faculty;
}
string Lecturer::getFaculty() {
	return this->faculty;
}
Schedule* Lecturer::getSchedule() {
	return this->sche;
}
void Lecturer::display() {
	cout << "Lecturer Name: " << this->getName() << endl;
	cout << "Faculty: " << this->getFaculty() << endl;
	this->sche->display();
}

//Manager
Manager::Manager(string name) : Staff(name) {}
void Manager::display() {
	cout << "Manager Name: " << this->getName() << endl;
}
//Subject
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
	cout << "Subject ID: " << this->getID() << endl;
	cout << "Subject Name: " << this->getName() << endl;
}
//Room
Room::Room(string name, int size) {
	this->setName(name);
	this->setSize(size);
}
void Room::setName(string name) {
	this->name = name;
}
void Room::setSize(int size) {
	this->size = size;
}
string Room::getName() {
	return this->name;
}
int Room::getSize() {
	return this->size;
}
void Room::display() {
	cout << "Room Name: " << this->getName() << endl;
	cout << "Room Size: " << this->getSize() << endl;
}
//Schedule
Schedule::Schedule() {}
void Schedule::addClassroom(Classroom* classroom) {
	this->classrooms.push_back(classroom);
}
void Schedule::display() {
	cout << "Schedule:" << endl;
	for (auto& classroom : classrooms) {
		classroom->display();
	}
}
//Classroom
Classroom::Classroom(string time, Room* room, Subject* subject) {
	this->setTime(time);
	this->setRoom(room);
	this->setSubject(subject);
}
void Classroom::setTime(string time) {
	this->time = time;
}
void Classroom::setRoom(Room* room) {
	this->room = room;
}
void Classroom::setSubject(Subject* subject) {
	this->subject = subject;
}
string Classroom::getTime() {
	return this->time;
}
Room* Classroom::getRoom() {
	return this->room;
}
Subject* Classroom::getSubject() {
	return this->subject;
}
void Classroom::display() {
	cout << "Classroom Time: " << this->getTime() << endl;
	this->getRoom()->display();
	this->getSubject()->display();
}
//des
Lecturer::~Lecturer() {
	delete sche;
}
Schedule::~Schedule() {
	for (auto c : classrooms)
		delete c;
}
//Main function
//int main() {
//	Lecturer* alice = new Lecturer("Alice", "Mathematics and Computer Science");
//	Subject* subject1 = new Subject("MTH10405", "DSA");
//	Subject* subject2 = new Subject("MTH10407", "OOP");
//	Room* room = new Room("C204", 40);
//	Classroom* class1 = new Classroom("2023-2024-HK2-Tue", room, subject1);
//	Classroom* class2 = new Classroom("2023-2024-HK2-Wed", room, subject2);
//	alice->getSchedule()->addClassroom(class1);
//	alice->getSchedule()->addClassroom(class2);
//	alice->display();
//	delete alice;
//	delete subject1;
//	delete subject2;
//	delete room;
//	return 0;
//}

