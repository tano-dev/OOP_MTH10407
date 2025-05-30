#include<iostream>
#include<string.h>
#include<list>
#include<map>
using namespace std;
class Employee;
class Doctor;
class Advisor;
class Hospital;
class Faculty;
class Patient;

class Employee{
private:
	string name;
	string address;
	Hospital* hospital;
public:
	Employee(string name,string address);

	//Getter & Setter
	void setName(string name);
	void setAddress(string address);
	void setHospital(Hospital* hospital);

	string getName();
	string getAddress();
	Hospital* getHospital();

	//Other Methods
	virtual void display();
};

class Doctor:public Employee{
private:
	string roomID;
	Advisor* advisor;
public:
	Doctor(string name,string address,string roomID);

	//Getter & Setter
	void setRoomID(string roomID);
	void setAdvisor(Advisor* advisor);

	string getRoomID();
	Advisor* getAdvisor();
	//Other Methods
	void display();
};

class Advisor:public Doctor{
private:
	list<Patient*> patients;
	list<Doctor*> doctors;
public:
	Advisor(string name,string address,string roomID);
	//Setter & Getter 
	void curePatient(string name,string dateOfBirth,string roomID);
	void setDoctor(Doctor* doctor);

	list<Patient*> getPatients();
	list<Doctor*> getDoctor();
	//Other Methods
	void display();
	void displayDoctor();
};

class Hospital{
private:
	string name;
	list<Faculty*> faculties;
	list<Employee*> employees;
public:
	Hospital(string name);

	//Setter & Getter
	void setName(string name);
	void setFaculty(Faculty* faculty);
	void setEmployee(Employee* employee);

	string getName();
	list<Faculty*> getFaculties();
	list<Employee*> getEmployee();
	//Other Methods
	void display();

};

class Faculty{
private:
	string name;
	list<Patient*> patients;
public:
	Faculty(string name);
	//Setter & Getter
	void setName(string name);
	void setPatient(Patient* patient);

	string getName();
	list<Patient*> getPatient();
	//Other Methods
	void display();
};

class Patient{
private:
	string name;
	string dateOfBirth;
	string roomID;
	Advisor* advisor;
public:
	Patient(string name,string dateOfBirth,string roomID);

	//Setter & Getter
	void setName(string name);
	void setDateOfBirth(string dateOfBirth);
	void setRoomID(string roomID);
	void registerCure(Advisor* advisor);

	string getName();
	string getDateOfBirth();
	string getRoomID();
	Advisor* getAdvisor();

	//Other Methods
	void display();

};
//Class Employee
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

void Employee::setHospital(Hospital* hospital){
	this->hospital = hospital;
}

string Employee::getName() {
    return this->name;
}

string Employee::getAddress() {
    return this->address;
}

Hospital* Employee::getHospital(){
	return this->hospital;
}

void Employee::display(){
	cout<<"Name : " << this->getName()<<'\n'<< "Address : " << this->getAddress()<<"\n";
}


//Class Doctor
Doctor::Doctor(string name,string address,string roomID):Employee(name,address) {
    this->setRoomID(roomID);
}

void Doctor::setRoomID(string roomID) {
    this->roomID = roomID;
}

void Doctor::setAdvisor(Advisor* advisor){
	this->advisor = advisor;
}

string Doctor::getRoomID() {
    return this->roomID;
}

Advisor* Doctor::getAdvisor(){
	return this->advisor;
}

void Doctor::display(){
	Employee::display();
	cout<<"RoomID :" << this->getRoomID() <<"\n\n";
}

//Class Advisor
Advisor::Advisor(string name,string address,string roomID):Doctor(name,address,roomID){};

void Advisor::curePatient(string name,string dateOfBirth,string roomID){
	Patient* tmp = new Patient(name,dateOfBirth,roomID);
	this->patients.push_back(tmp);
}

void Advisor::setDoctor(Doctor* doctor){
	bool ok = true;
	for(Doctor* it : this->doctors){
		if(it == doctor ){
			ok = false; break;
		}
	}
	if(ok){
		this->doctors.push_back(doctor);
		doctor->setAdvisor(this);
}
	}
	

list<Patient*> Advisor::getPatients(){
	return patients;
}

list<Doctor*> Advisor::getDoctor(){
	return doctors;
}

void Advisor::display(){
	Doctor::display();
}

void Advisor::displayDoctor(){
	cout<<"Information of group doctors that " << this->getName() << " managed\n" ;
	int i=0;
	for(auto it : this->doctors){
		cout<<'#'<<++i<<'\n';
		it->display();
		cout<<'\n';
	}
	cout<<"================================"<<'\n';
}
//Class Hospital
Hospital::Hospital(string name) {
    this->setName(name);
}

void Hospital::setName(string name) {
    this->name = name;
}

void Hospital::setFaculty(Faculty* faculty){
	this->faculties.push_back(faculty);
}

void Hospital::setEmployee(Employee* employee){
	this->employees.push_back(employee);
	employee->setHospital(this);
}

string Hospital::getName() {
    return this->name;
}

list<Faculty*> Hospital::getFaculties(){
	return faculties;
}

list<Employee*> Hospital::getEmployee(){
	return employees;
}

void Hospital::display(){
	cout<<"Name Hospital : " << this->getName() <<"\n\n";
}


//Class Faculty
Faculty::Faculty(string name) {
    this->setName(name);
}

void Faculty::setName(string name) {
    this->name = name;
}

void Faculty::setPatient(Patient* patient){
	this->patients.push_back(patient);
}

string Faculty::getName() {
    return this->name;
}

list<Patient*> Faculty::getPatient(){
	return patients;
}

void Faculty::display(){
	cout<<"Name of Faculty: "<< this->getName() <<"\n\n";
}

//Class Patient
Patient::Patient(string name, string dateOfBirth, string roomID) {
    this->setName(name);
    this->setDateOfBirth(dateOfBirth);
    this->setRoomID(roomID);
}

void Patient::setName(string name) {
    this->name = name;
}

void Patient::setDateOfBirth(string dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Patient::setRoomID(string roomID) {
    this->roomID = roomID;
}

void Patient::registerCure(Advisor* advisor){
	this->advisor = advisor;
	advisor->curePatient(this->getName(), this->getDateOfBirth(), this->getRoomID());
}

string Patient::getName() {
    return this->name;
}

string Patient::getDateOfBirth() {
    return this->dateOfBirth;
}

string Patient::getRoomID() {
    return this->roomID;
}

Advisor* Patient::getAdvisor(){
	return this->advisor;
}

void Patient::display(){
	cout<<"Name Patient : "<< this->getName() <<'\n';
	cout<<"DateOfBirth : "<< this->getDateOfBirth() <<'\n';
	cout<<"Room ID: "<< this->getRoomID()<<"\n\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	Hospital* h = new Hospital("Bach Mai");
	Faculty* external = new Faculty("Khoa noi");
	Doctor* d1 = new Doctor("Nguyen Van A","Ha Noi","P100");
	Doctor* d2 = new Doctor("Nguyen Van B","Ha Noi","P101");
	Doctor* d3 = new Doctor("Nguyen Van C","Ha Noi","P101");
	Doctor* d4 = new Doctor("Nguyen Van D","Ha Noi","P102");
	Advisor* a = new Advisor("Nguyen Van Muoi","Ha Noi","110");
	Advisor* b = new Advisor("Louis Pierre ","Paris","111");
	Patient* p = new Patient("Nguyen Thi Dao","04/12/1997","210");
	Patient* p1 = new Patient("Le Van Teo","07/04/2000","201");
	h->setEmployee(d1);
	h->setEmployee(d2);
	h->setEmployee(d3);
	h->setEmployee(d4);
	h->setEmployee(a);
	h->setEmployee(b);
	h->setFaculty(external);
	a->setDoctor(d1);
	a->setDoctor(d2);
	b->setDoctor(d3);
	b->setDoctor(d4);
	p->registerCure(a);
	p1->registerCure(b);
	h->display();
	external->display();
	cout<<"Benh nhan " << p->getName() <<'\n';
	cout<<"Thong tin"<<'\n';
	p->display();
	cout<< "Thong tin bac si dieu tri\n";
	a->display();
	a->displayDoctor();
	cout<<"Benh nhan " << p1->getName() <<'\n';
	cout<<"Thong tin"<<'\n';
	p1->display();
	cout<< "Thong tin bac si dieu tri\n";
	b->display();
	b->displayDoctor();
	delete h;
	delete external;
	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete a;
	delete b;
	delete p;
	delete p1;
	return 0;
}