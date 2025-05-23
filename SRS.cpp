#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;
//Class defining
class Course;
class Section;
class Student;
class Professor;
class ScheduleOfClasses;
class Person;
class Transcript;
class TranscriptEntry;
//Class init
class Course {
private:
	string courseName;
	string courseNo;
	int credits;
	list<Section*> sections;
	list<Course*> prerequisites;
public:
	Course(string courseName, string courseNo, int credits);
	void setCourseName(string courseName);
	void setCourseNo(string courseNo);
	void setCredits(int credits);
	string getCourseName();
	string getCourseNo();
	int getCredits();
	void scheduleSection(Section* section);
	void addPrerequisite(Course* course);
	bool hasPrerequisites();
	void displayPrerequisites();
	void displaySections();
	void display();
	~Course();
};
class Section {
private:
	string sectionNo;
	string dayOfWeek;
	string timeOfDay;
	string room;
	int seatCapacity;
	Course* course;
	list<Student*> students;
	Professor* professor;
public:
	Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatCapacity);
	void setSectionNo(string sectionNo);
	void setDayOfWeek(string dayOfWeek);
	void setTimeOfDay(string timeOfDay);
	void setRoom(string room);
	void setSeatCapacity(int seatCapacity);
	string getSectionNo();
	string getDayOfWeek();
	string getTimeOfDay();
	string getRoom();
	int getSeatCapacity();
	void enroll();
	void drop();
	void postGrade();
	void comfirmSeatAvailability();
	void display();
};
class ScheduleOfClasses {
private:
	string semester;
	map<string, Section*> sections;
public:
	ScheduleOfClasses(string semester);
	void setSemester(string semester);
	string getSemester();
	void addSection(Section* section);
	void display();
};
class Person {
private:
	string ssn;
	string name;
public:
	Person(string ssn, string name);
	void setSsn(string ssn);
	void setName(string name);
	string getSsn();
	string getName();
	void display();
};
class Student : public Person {
private:
	string degree;
	string major;
	Transcript* transcript;
	list<Section*> sections;
public:
	Student(string ssn, string name, string degree, string major);
	void setDegree(string degree);
	void setMajor(string major);
	string getDegree();
	string getMajor();
	void addSection(Section* section);
	void dropSection(Section* section);
	bool isEnrolledIn(Section* section);
	void display();
};
class Professor : public Person {
private:
	string title;
	string department;
	list<Section*> teaches;
public:
	Professor(string ssn, string name, string title, string department);
	void setTitle(string title);
	void setDepartment(string department);
	string getTitle();
	string getDepartment();
	void agreeToTeach(Section* section);
	void display();
};
class Transcript {
private:
	Student* student;
	map<string, TranscriptEntry*> entries;
public:
	Transcript() {};
	void setStudent(Student* student);
	void addEntry(TranscriptEntry* entry);
	void display();
};
class TranscriptEntry {
private:
	float grade;
public:
	TranscriptEntry(float grade);
	void setGrade(float grade);
	float getGrade();
	void display();
};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Course
Course::Course(string courseName, string courseNo, int credits) {
	this->setCourseName(courseName);
	this->setCourseNo(courseNo);
	this->setCredits(credits);
}
void Course::setCourseName(string courseName) {
	this->courseName = courseName;
}
void Course::setCourseNo(string courseNo) {
	this->courseNo = courseNo;
}
void Course::setCredits(int credits) {
	this->credits = credits;
}
string Course::getCourseName() {
	return this->courseName;
}
string Course::getCourseNo() {
	return this->courseNo;
}
int Course::getCredits() {
	return this->credits;
}
void Course::scheduleSection(Section* section) {
	this->sections.push_back(section);
}
void Course::addPrerequisite(Course* course) {
	this->prerequisites.push_back(course);
}
bool Course::hasPrerequisites() {
	return !this->prerequisites.empty();
}
void Course::displayPrerequisites() {
	if (!this->hasPrerequisites()) {
		cout << "No prerequisites." << endl;
		return;
	}
	cout << "Prerequisites: " << endl;
	for (auto i : this->prerequisites) {
		i->display();
	}
}
void Course::displaySections() {
	cout << "Sections: " << endl;
	for (auto i : this->sections) {
		i->display();
	}
}
void Course::display() {
	cout << "Course Name: " << this->getCourseName() << endl;
	cout << "Course No: " << this->getCourseNo() << endl;
	cout << "Credits: " << this->getCredits() << endl;
	this->displayPrerequisites();
	this->displaySections();
}
Course::~Course() {
	for (auto i : this->sections) {
		delete i;
	}
}
//Section
Section::Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatCapacity) {
	this->setSectionNo(sectionNo);
	this->setDayOfWeek(dayOfWeek);
	this->setTimeOfDay(timeOfDay);
	this->setRoom(room);
	this->setSeatCapacity(seatCapacity);
}
void Section::setSectionNo(string sectionNo) {
	this->sectionNo = sectionNo;
}
void Section::setDayOfWeek(string dayOfWeek) {
	this->dayOfWeek = dayOfWeek;
}
void Section::setTimeOfDay(string timeOfDay) {
	this->timeOfDay = timeOfDay;
}
void Section::setRoom(string room) {
	this->room = room;
}
void Section::setSeatCapacity(int seatCapacity) {
	this->seatCapacity = seatCapacity;
}
string Section::getSectionNo() {
	return this->sectionNo;
}
string Section::getDayOfWeek() {
	return this->dayOfWeek;
}
string Section::getTimeOfDay() {
	return this->timeOfDay;
}
string Section::getRoom() {
	return this->room;
}
int Section::getSeatCapacity() {
	return this->seatCapacity;
}
void Section::enroll() {
	cout << "Enrolling in section " << this->getSectionNo() << endl;
}
