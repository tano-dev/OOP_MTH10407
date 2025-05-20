#include<iostream>
#include<string>
#include<list>

using namespace std;

class Employee;
class Programmer;
//class SoftwareHouse;

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
    //
    void display();

};
class Programmer:public Employee {
private:
    string language;
public:
    //
    void setLanguage(string language);
    string getLanguage();
    Programmer(string number, string name, double salary, string language);
    void display();
};

void Employee::setNumber(string number) {
    this->number = number;
}
void Employee::setName(string name) {
    this->name = name;
}
void Employee::setSalary(double salary) {
    this->salary = salary;
}
