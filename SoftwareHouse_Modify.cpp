#include<iostream>
#include<string>
#include<list>

using namespace std;
//Class defining
class Employee;
class Programmer;
class SoftwareHouse;
class ProjectLeader;
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
    void display();

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
    list<Programmer*> programmerList;
    list<ProjectLeader*> leaders;
public:
    SoftwareHouse(string number);
    void setNumber(string number);
    string getNumber();
    void addProgrammer(Programmer* prog);
    void addLeader(ProjectLeader* projectLeader);
    void display();
};
class ProjectLeader :public Programmer {
private:
    list<Programmer*> programmers;
public:
    ProjectLeader(string number, string name, double salary, string language); //constructor
    void addProgrammer(Programmer* p);
    void displayProgrammers();
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
void SoftwareHouse::addProgrammer(Programmer* prog) {
    this->programmerList.push_back(prog);
}
void SoftwareHouse::addLeader(ProjectLeader* projectLeader) {
    this->leaders.push_back(projectLeader);
}
void SoftwareHouse::display() {
    cout << "Software House Number: " << this->getNumber() << endl;
    cout << "Project leaders:" << endl;
    for (auto i : this->leaders) {
        i->display();
    }
    cout << "Programmers in " << this->getNumber() << ": " << endl;
    for (auto i : this->programmerList) {
        i->display();
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
    cout << "Leader's info:" << endl;
    Programmer::display();
    displayProgrammers();
}

//int main() {
//    Programmer* p1 = new Programmer("001", "p1", 100, "python");
//    Programmer* p2 = new Programmer("002", "p2", 500, "c++");
//    Programmer* p3 = new Programmer("003", "p3", 250, "c++");
//    SoftwareHouse* sh1 = new SoftwareHouse("001");
//    ProjectLeader* ld1 = new ProjectLeader("000", "owner", 1000, "all");
//
//    sh1->addProgrammer(p1);
//    sh1->addProgrammer(p2);
//    sh1->addProgrammer(p3);
//    sh1->addLeader(ld1);
//    ld1->addProgrammer(p1);
//    ld1->addProgrammer(p2);
//
//
//
//    sh1->display();
//
//    delete p1;
//    delete p2;
//    delete sh1;
//}



