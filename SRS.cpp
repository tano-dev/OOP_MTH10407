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
	map<Student*, TranscriptEntry> entries;
public:
	Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatCapacity);
	void setSectionNo(string sectionNo);
	void setDayOfWeek(string dayOfWeek);
	void setTimeOfDay(string timeOfDay);
	void setRoom(string room);
	void setSeatCapacity(int seatCapacity);
	void setProfessor(Professor* professor);
	void setCourse(Course* course);

	string getSectionNo();
	string getDayOfWeek();
	string getTimeOfDay();
	string getRoom();
	int getSeatCapacity();
	Course* getCourse();
	void enroll(Student* student);
	void drop(Student* student);
	void postGrade(Student* student,float grade);
	bool comfirmSeatAvailability();
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
	virtual void display();
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
	void setTranscript(Transcript* transcript);
	string getDegree();
	string getMajor();
	void addSection(Section* section);
	void dropSection(Section* section);
	bool isEnrolledIn(Section* section);
	void display();
	void displayAll();
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
	void displayAll();
};
class Transcript {
private:
	Student* student;
	list<TranscriptEntry*> entries;
public:
	Transcript(Student* student);
	void setStudent(Student* student);
	void addEntry(TranscriptEntry* entry);
	string verifyCompletion(Course* course);
	void display();
};
class TranscriptEntry {
private:
	float grade;
	Section* section;
public:
	TranscriptEntry(float grade,Section* section);
	void setGrade(float grade);
	void setSection(Section* section);
	float getGrade();
	Section* getSection();
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
	cout << " >Prerequisites: " << endl;
	for (auto i : this->prerequisites) {
		i->display();
	}
}
void Course::displaySections() {
	cout << " >Sections: " << endl;
	for (auto i : this->sections) {
		i->display();
	}
}
void Course::display() {
	cout << " + Course Name: " << this->getCourseName() << endl;
	cout << " + Course No: " << this->getCourseNo() << endl;
	cout << " + Credits: " << this->getCredits() << endl;
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
Course* Section::getCourse() {
	return this->course;
}
bool Section::comfirmSeatAvailability() {
	return this->students.size() < this->getSeatCapacity();
}
void Section::setProfessor(Professor* professor) {
	this->professor = professor;
}
void Section::setCourse(Course* course) {
	this->course = course;
}
void Section::enroll(Student* student) {
	if (this->comfirmSeatAvailability() && !student->isEnrolledIn(this)) {
		this->students.push_back(student);
		student->addSection(this);
	}
}
void Section::drop(Student* student) {
	if (student->isEnrolledIn(this)) {
		this->students.remove(student);
		student->dropSection(this);
	}
}
/*
self-note:
entries.find(student) tra ve Object neu tim thay
entries.find(end) tra ve Object "NULL" o cuoi map
*/
void Section::postGrade(Student* student, float grade) {
	if (student->isEnrolledIn(this)) return;
	if (entries.find(student) != entries.end()) return;
	entries[student] = TranscriptEntry(grade,this);
}
void Section::display() {
	cout << "------------------------------------------------ " << endl;
	cout << "Section: " << this->getSectionNo() << endl;
	cout << "Day of Week: " << this->getDayOfWeek() << endl;
	cout << "Time of Day: " << this->getTimeOfDay() << endl;
	cout << "Room: " << this->getRoom() << endl;
	cout << "Seat Capacity: " << this->getSeatCapacity() << endl;
	cout << "Course: " << endl;
	this->course->display();
	cout << "Professor: " << endl;
	this->professor->display();
	cout << "Students: " << endl;
	for (auto i : this->students) {
		i->display();
	}
}
//ScheduleOfClasses
ScheduleOfClasses::ScheduleOfClasses(string semester) {
	this->setSemester(semester);
}
void ScheduleOfClasses::setSemester(string semester) {
	this->semester = semester;
}
string ScheduleOfClasses::getSemester() {
	return this->semester;
}
void ScheduleOfClasses::addSection(Section* section) {
	this->sections[section->getSectionNo()] = section;
}
void ScheduleOfClasses::display() {
	cout << "Schedule of Classes for " << this->getSemester() << ":" << endl;
	for (auto i : this->sections) {
		i.second->display();
	}
}
//Person
Person::Person(string ssn, string name) {
	this->setSsn(ssn);
	this->setName(name);
}
void Person::setSsn(string ssn) {
	this->ssn = ssn;
}
void Person::setName(string name) {
	this->name = name;
}
string Person::getSsn() {
	return this->ssn;
}
string Person::getName() {
	return this->name;
}
void Person::display() {
	cout << "-SSN: " << this->getSsn() << endl;
	cout << "-Name: " << this->getName() << endl;
}
//Student
Student::Student(string ssn, string name, string degree, string major):Person(ssn, name) {
	this->setDegree(degree);
	this->setMajor(major);
}
void Student::setDegree(string degree) {
	this->degree = degree;
}
void Student::setMajor(string major) {
	this->major = major;
}
void Student::setTranscript(Transcript* transcript) {
	this->transcript = transcript;
}
string Student::getDegree() {
	return this->degree;
}
string Student::getMajor() {
	return this->major;
}
bool Student::isEnrolledIn(Section* section) {
	for (auto i : this->sections) {
		if (i == section) {
			return true;
		}
	}
	return false;
}
void Student::addSection(Section* section) {
	this->sections.push_back(section);
}
void Student::dropSection(Section* section) {
	this->sections.remove(section);
}
void Student::display() {
	Person::display();
	cout << " + Degree: " << this->getDegree() << endl;
	cout << " + Major: " << this->getMajor() << endl;
}
void Student::displayAll() {
	cout << "Student Details: " << endl;
	this->display();
	cout << "Enrolled Sections: " << endl;
	for (auto i : this->sections) {
		cout << "   -" << i->getSectionNo() << endl;
	}
}
//Professor
Professor::Professor(string ssn, string name, string title, string department) : Person(ssn, name) {
	this->setTitle(title);
	this->setDepartment(department);
}
void Professor::setTitle(string title) {
	this->title = title;
}
void Professor::setDepartment(string department) {
	this->department = department;
}
string Professor::getTitle() {
	return this->title;
}
string Professor::getDepartment() {
	return this->department;
}
void Professor::agreeToTeach(Section* section) {
	this->teaches.push_back(section);
	section->setProfessor(this);
}
void Professor::display() {
	Person::display();
	cout << " + Title: " << this->getTitle() << endl;
	cout << " + Department: " << this->getDepartment() << endl;
}
void Professor::displayAll() {
	cout << "Professor Details: " << endl;
	this->display();
	cout << "Teaches Sections: " << endl;
	for (auto i : this->teaches) {
		cout << "   -" << i->getSectionNo() << endl;
	}
}
//Transcript
Transcript::Transcript(Student* student) {
	this->setStudent(student);
}
void Transcript::setStudent(Student* student) {
	this->student = student;
}
void Transcript::addEntry(TranscriptEntry* entry) {
	this->entries.push_back(entry);
}
string Transcript::verifyCompletion(Course* course) {
	for (auto i : this->entries) {
		if (i->getSection()->getCourse() == course) {
			if (i->getGrade() >= 5) {
				return "gg passed W gamer";
			}
			else {
				return "L bozo";
			}
		}
	}
	return "Bro hasn't completed the course";
}
void Transcript::display() {
	cout << "   >Transcript for: " << this->student->getName() << endl;
	for (auto i : this->entries) {
		cout << "    +Section: " << i->getSection()->getSectionNo() << ", Grade: " << i->getGrade() << endl;
	}
	if (this->entries.empty()) {
		cout << "    -No entries found." << endl;
	}
}
//TranscriptEntry
TranscriptEntry::TranscriptEntry(float grade,Section* section) {
	this->setGrade(grade);
	this->setSection(section);
}
void TranscriptEntry::setGrade(float grade) {
	this->grade = grade;
}
float TranscriptEntry::getGrade() {
	return this->grade;
}
void TranscriptEntry::setSection(Section* section) {
	this->section = section;
}
Section* TranscriptEntry::getSection() {
	return this->section;
}
// Main function to demonstrate the classes
int main() {
	// Create courses
	Course* course1 = new Course("Data Structures", "CS101", 3);
	Course* course2 = new Course("Algorithms", "CS102", 3);
	Course* course3 = new Course("Operating Systems", "CS103", 4);
	// Add prerequisites
	course2->addPrerequisite(course1);
	course3->addPrerequisite(course2);
	// Create sections
	Section* section1 = new Section("001", "Monday", "10:00 AM", "Room 101", 30);
	Section* section2 = new Section("002", "Wednesday", "11:00 AM", "Room 102", 30);
	// Set course for sections
	section1->setCourse(course1);
	section2->setCourse(course2);
	// Create a professor
	Professor* prof1 = new Professor("123-45-6789", "Dr. Smith", "Associate Professor", "Computer Science");
	prof1->agreeToTeach(section1);
	prof1->agreeToTeach(section2);
	// Create students
	Student* student1 = new Student("987-65-4321", "Alice Johnson", "Bachelor of Science", "Computer Science");
	Student* student2 = new Student("876-54-3210", "Bob Smith", "Bachelor of Arts", "Mathematics");
	// Enroll students in sections
	section1->enroll(student1);
	section2->enroll(student2);
	// Create a schedule of classes
	ScheduleOfClasses schedule("Fall 2023");
	schedule.addSection(section1);
	schedule.addSection(section2);
	// Display the schedule of classes
	schedule.display();
	// Display course details
	course1->display();
	course2->display();
	course3->display();
	// Display student details
	student1->displayAll();
	student2->displayAll();
	// Display professor details
	prof1->displayAll();
	// Clean up memory
	delete course1;
	delete course2;
	delete course3;
	delete section1;
	delete section2;
	delete prof1;
	delete student1;
	delete student2;
	return 0;
}