#include<iostream>
#include<string>
#include<list>

using namespace std;

class Employee;
class Programmer;
class SoftwareHouse;
//Class defining
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
    void display();

};
class Programmer:public Employee {
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
    list<Programmer*> programmerList;
public:
    SoftwareHouse(string number);
    void setNumber(string number);
    string getNumber();
    void addProgrammer(Programmer* prog);
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
	cout << "Number: " << this->getNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Salary: " << this->getSalary() << endl;
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
    cout << "Language: " << this->getLanguage() << endl;
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
void SoftwareHouse::addProgrammer(Programmer* prog) {
	this->programmerList.push_back(prog);
}
void SoftwareHouse::display() {
	cout << "Software House Number: " << this->getNumber() << endl;
	cout << "Programmers: " << endl;
	for (auto i : this->programmerList) {
		i->display();
	}
}
int main() {
    Programmer* p1 = new Programmer("001", "p1", 100, "python");
    Programmer* p2 = new Programmer("002", "p2", 500, "tieng Viet");

    SoftwareHouse* sh1 = new SoftwareHouse("001");
    sh1->addProgrammer(p1);
    sh1->addProgrammer(p2);
    sh1->display();

    delete p1;
    delete p2;
    delete sh1;
}



