#include<iostream>
#include<string>
#include<list>
#include<map>

using namespace std;
//Class defining
class Employee;
class Programmer;
class SoftwareHouse;
class ProjectLeader;
class Administrator;
//Class init
class Employee {
private:
	string number;
	string name;
	double salary;
public:
	void setNumber(string number);
	void setName(string name);
	void setSalary(double salary);
	string getNumber();
	string getName();
	double getSalary();
	Employee(string number, string name, double salary);
	virtual void display();
};
class Programmer :public Employee {
private:
	string language;
public:
	void setLanguage(string language);
	string getLanguage();
	Programmer(string number, string name, double salary, string language);
	void display();
};
class SoftwareHouse {
private:
	string number;
	map<string, Employee*> staffList;
public:
	SoftwareHouse(string number);
	void setNumber(string number);
	string getNumber();
	void addStaff(Employee* staff);
	void display();
};
class ProjectLeader :public Programmer {
private:
	list<Programmer*> programmers;
public:
	ProjectLeader(string number, string name, double salary, string language);
	void addProgrammer(Programmer* p);
	void displayProgrammers();
	void display();
};
class Administrator :public Employee {
private:
	string department;
public:
	Administrator(string number, string name, double salary, string department);
	void setDepartment(string department);
	string getDepartment();
	void display();
};

//Employee
void Employee::setNumber(string number) {
	this->number = number;
}
void Employee::setName(string name) {
	this->name = name;
}
void Employee::setSalary(double salary) {
	this->salary = salary;
}
string Employee::getNumber() {
	return this->number;
}
string Employee::getName() {
	return this->name;
}
double Employee::getSalary() {
	return this->salary;
}
Employee::Employee(string number, string name, double salary) {
	this->setNumber(number);
	this->setName(name);
	this->setSalary(salary);
}
void Employee::display() {
	cout << " +Number: " << this->getNumber() << endl;
	cout << " +Name: " << this->getName() << endl;
	cout << " +Salary: " << this->getSalary() << endl;
}
//Programmer
Programmer::Programmer(string number, string name, double salary, string language) : Employee(number, name, salary) {
	this->setLanguage(language);
}
void Programmer::setLanguage(string language) {
	this->language = language;
}
string Programmer::getLanguage() {
	return this->language;
}

void Programmer::display() {
	cout << "-Language: " << this->getLanguage() << endl;
	Employee::display();
}
//SoftwareHouse
SoftwareHouse::SoftwareHouse(string number) {
	this->setNumber(number);
}
void SoftwareHouse::setNumber(string number) {
	this->number = number;
}
string SoftwareHouse::getNumber() {
	return this->number;
}
void SoftwareHouse::addStaff(Employee* staff) {
	this->staffList[staff->getNumber()] = staff;
}
void SoftwareHouse::display() {
	if (this->staffList.empty()) {
		cout << "No staff in the software house." << endl;
		return;
	}
	cout << "Software House Number: " << this->getNumber() << endl;
	cout << "Staff List: " << endl;
	for (auto i : this->staffList) {
		cout << ">Staff Number: " << i.first << endl;
		i.second->display();
	}
}
//ProjectLeader
ProjectLeader::ProjectLeader(string number, string name, double salary, string language) : Programmer(number, name, salary, language) {}
void ProjectLeader::addProgrammer(Programmer* p) {
	this->programmers.push_back(p);
}
void ProjectLeader::displayProgrammers() {
	cout << "Leader's programmers:" << endl;
	for (auto i : this->programmers) {
		i->display();
	}
}
void ProjectLeader::display() {
	cout << this->getNumber() <<"'s info:" << endl;
	Programmer::display();
	displayProgrammers();
}
//Administrator
Administrator::Administrator(string number, string name, double salary, string department) : Employee(number, name, salary) {
	this->setDepartment(department);
}
void Administrator::setDepartment(string department) {
	this->department = department;
}
string Administrator::getDepartment() {
	return this->department;
}
void Administrator::display() {
	cout << "Department: " << this->getDepartment() << endl;
	Employee::display();
}

//int main() {
//	Programmer a("001", "John", 1000, "C++");
//	Programmer b("002", "Jane", 2000, "Java");
//	Programmer e("004", "Jack", 2000, "Java");
//	ProjectLeader c("003", "Jack", 4000, "Python");
//	Administrator f("005", "Jill", 3000, "HR");
//	c.addProgrammer(&a);
//	c.addProgrammer(&b);
//
//	SoftwareHouse d("Facebook");
//	d.addStaff(&a);
//	d.addStaff(&b);
//	d.addStaff(&c);
//	d.addStaff(&e);
//	d.addStaff(&f);
//	d.display();
//	return 0;
//}

