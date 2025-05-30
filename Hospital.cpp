/*
Một bệnh viện bao gồm nhiều khoa. Mỗi khoa có một tên riêng.

Mỗi khoa có nhiều bệnh nhân. Bệnh nhân có các thông tin về tên, ngày sinh. Bệnh nhân chỉ ở trong một khoa duy nhất.

Các bác sĩ trong bệnh viện được tổ chức theo nhóm. Mỗi bác sĩ chỉ ở trong một nhóm. Mỗi nhóm có một mã nhóm duy nhất. Mỗi nhóm được lãnh đạo bởi một bác sĩ (cố vấn) duy nhất. Bác sĩ có các thông tin về tên, địa chỉ.

Mỗi bệnh nhân khi nhập bệnh viện được điều trị bởi một nhóm bác sĩ duy nhất. Bác sĩ cố vấn của nhóm đó chịu trách nhiệm về bệnh nhân.

Chương trình cần quản lý các thông tin sau:
Các khoa.
Các bác sĩ, và nhóm của bác sĩ đó.
Bệnh nhân và phòng bệnh của bệnh nhân khi nhập viện. Hiển thị thông tin bác sĩ tư vấn chịu trách nhiệm cho bệnh nhân đó. Hiển thị nhóm bác sĩ đang điều trị cho bệnh nhân.
*/
#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;

class Hospital;
class Faculty;
class Patient;
class Doctor;
class Advisor;
class Employee;

class Hospital {
private:
	string name;
	map<string, Faculty*> faculties;
	map<string, Employee*> employees;
public:
	Hospital(string name);
	void setName(string name);
	string getName();
	void addEmployee(Employee* employee);
	void addFaculty(Faculty* faculty);
	void display();
};
class Employee {
private:
	string name;
	string address;
public:
	Employee(string name, string address);
	void setName(string name);
	void setAddress(string address);
	string getName();
	string getAddress();
	virtual void display();
};
class Faculty {
private:
	string name;
	list<Patient*> patients;
public:
	Faculty(string name);
	void setName(string name);
	string getName();
	void addPatient(Patient* patient);
	virtual void display();
};
class Patient {
private:
	string name;
	string birthday;
	string room;
	Faculty* faculty;
	Advisor* advisor;
public:
	Patient(string name, string birthday, string room);
	void setName(string name);
	void setBirthday(string birthday);
	void setRoom(string room);
	void setFaculty(Faculty* faculty);
	void setAdvisor(Advisor* advisor);	
	string getName();
	string getBirthday();
	string getRoom();
	void display();
};
class Doctor :public Employee {
private:
	int groupID;
	Advisor* advisor;
public:
	Doctor(string name,string address,int id);
	void setRoomID(int roomID);
	void setAdvisor(Advisor* advisor);
	int getGroupID();
	void display();
};
class Advisor :public Doctor {
private:
	list<Patient*> patients;
	list<Doctor*> doctors;
public:
	Advisor(string name, string address, int id);
	void registration(Patient* patient);
	void addDoctor(Doctor* doctor);
	void display();
};
//Hospital
Hospital::Hospital(string name) {
	this->setName(name);
}
void Hospital::setName(string name) {
	this->name = name;
}
string Hospital::getName() {
	return this->name;
}
void Hospital::addEmployee(Employee* employee) {
	employees[employee->getName()] = employee;
}
void Hospital::addFaculty(Faculty* faculty) {
	faculties[faculty->getName()] = faculty;
}
void Hospital::display() {
	cout << "Hospital Name: " << this->getName() << endl;
	cout << "Employees: " << endl;
	for (auto i : this->employees) {
		i.second->display();
	}
	cout << "Faculties: " << endl;
	for (auto i : this->faculties) {
		i.second->display();
	}
}
//Employee
Employee::Employee(string name, string address) {
	this->setName(name);
	this->setAddress(address);
}
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setAddress(string address) {
	this->address = address;
}
string Employee::getName() {
	return this->name;
}
string Employee::getAddress() {
	return this->address;
}
void Employee::display() {
	cout << "-- Name: " << this->getName() << endl;
	cout << "-- Address: " << this->getAddress() << endl;
}
//Faculty
Faculty::Faculty(string name) {
	this->setName(name);
}
void Faculty::setName(string name) {
	this->name = name;
}
string Faculty::getName() {
	return this->name;
}
void Faculty::addPatient(Patient* patient) {
	this->patients.push_back(patient);
	patient->setFaculty(this);
}
void Faculty::display() {
	cout << "Faculty Name: " << this->getName() << endl;
	cout << "Patients: " << endl;
	for (auto i : this->patients) {
		i->display();
	}
}
//Patient
Patient::Patient(string name, string birthday, string room) {
	this->setName(name);
	this->setBirthday(birthday);
	this->setRoom(room);
}
void Patient::setName(string name) {
	this->name = name;
}
void Patient::setBirthday(string birthday) {
	this->birthday = birthday;
}
void Patient::setRoom(string room) {
	this->room = room;
}
void Patient::setFaculty(Faculty* faculty) {
	this->faculty = faculty;
}
void Patient::setAdvisor(Advisor* advisor) {
	this->advisor = advisor;
}
string Patient::getName() {
	return this->name;
}
string Patient::getBirthday() {
	return this->birthday;
}
string Patient::getRoom() {
	return this->room;
}
void Patient::display() {
	cout << "----Patient Name: " << this->getName() << endl;
	cout << "----Birthday: " << this->getBirthday() << endl;
	cout << "----Room: " << this->getRoom() << endl;
	if (this->advisor) {
		cout << "----Advisor: " << this->advisor->getName() << endl;
	}
	if (this->faculty) {
		cout << "----Faculty: " << this->faculty->getName() << endl;
	}
}
Doctor::Doctor(string name, string address, int id) : Employee(name, address) {
	this->setRoomID(id);
}
void Doctor::setRoomID(int id) {
	this->groupID = id;
}
void Doctor::setAdvisor(Advisor* advisor) {
	this->advisor = advisor;
}
int Doctor::getGroupID() {
	return this->groupID;
}
void Doctor::display() {
	Employee::display();
	cout << "-- Group ID: " << this->getGroupID() << endl;
}
Advisor::Advisor(string name, string address, int id) : Doctor(name,address,id) {
}
void Advisor::registration(Patient* patient) {
	this->patients.push_back(patient);
	patient->setAdvisor(this);
}
void Advisor::addDoctor(Doctor* doctor) {
	bool exists = false;
	for (auto d : this->doctors) {
		if (d->getName() == doctor->getName()) {
			exists = true;
			break;
		}
	}
	if (!exists) {
		this->doctors.push_back(doctor);
		doctor->setAdvisor(this);
	}
}
void Advisor::display() {
	cout << "Advisor Name: " << this->getName() << endl;
	Doctor::display();
	cout << "Patients: " << endl;
	for (auto i : this->patients) {
		i->display();
	}
	cout << "Doctors under this advisor: " << endl;
	for (auto i : this->doctors) {
		i->display();
	}
	cout << "------------------------------" << endl;
}
//int main() {
//	Hospital* hospital = new Hospital("City Hospital");
//	Faculty* cardiology = new Faculty("Cardiology");
//	Employee* emp1 = new Employee("Alice", "123 Main St");
//	Employee* emp2 = new Employee("Bob", "456 Elm St");
//	Doctor* doc1 = new Doctor("Dr. Smith", "789 Oak St", 101);
//	Doctor* doc2 = new Doctor("Dr. Jones", "321 Pine St", 102);
//	Advisor* advisor1 = new Advisor("Dr. Brown", "654 Maple St", 201);
//	Patient* patient1 = new Patient("John Doe", "01/01/1990", "Room 101");
//	Patient* patient2 = new Patient("Jane Doe", "02/02/1992", "Room 102");
//	hospital->addEmployee(emp1);
//	hospital->addEmployee(emp2);
//	hospital->addEmployee(doc1);
//	hospital->addEmployee(doc2);
//	hospital->addEmployee(advisor1);
//	hospital->addFaculty(cardiology);
//	cardiology->addPatient(patient1);
//	cardiology->addPatient(patient2);
//	advisor1->registration(patient1);
//	advisor1->registration(patient2);
//	advisor1->addDoctor(doc1);
//	advisor1->addDoctor(doc2);
//	hospital->display();
//	delete hospital;
//	delete cardiology;
//	delete emp1;
//	delete emp2;
//	delete doc1;
//	delete doc2;
//	delete advisor1;
//	delete patient1;
//	delete patient2;
//	return 0;
//}