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
	map<Student*, TranscriptEntry*> entries;
public:
	Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatCapacity, ScheduleOfClasses* schedule, Course* course);
	void addSchedule(ScheduleOfClasses* schedule);
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
	Transcript* getTranscript();
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
	//void display();
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
	section->setCourse(this);
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
Section::Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatCapacity, ScheduleOfClasses* schedule, Course* course) {
	this->setSectionNo(sectionNo);
	this->setDayOfWeek(dayOfWeek);
	this->setTimeOfDay(timeOfDay);
	this->setRoom(room);
	this->setSeatCapacity(seatCapacity);
	this->addSchedule(schedule);
	course->scheduleSection(this);
}

void Section::addSchedule(ScheduleOfClasses* schedule) {
	schedule->addSection(this);
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
	//cout << "a" << endl;
	if (!student->isEnrolledIn(this)) return;
	//cout << "b" << endl;
	if (entries.find(student) != entries.end()) return;
	//cout << "c" << endl;
	TranscriptEntry* entry = new TranscriptEntry(grade, this);
	entries[student] = entry;
	student->getTranscript()->addEntry(entry);
	//cout << "d"<< endl;
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
	Transcript* transcript = new Transcript(this);
	this->setTranscript(transcript);
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
Transcript* Student::getTranscript() {
	return this->transcript;
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
		
		cout << "   -" << i->getSectionNo() <<": " << this->getTranscript()->verifyCompletion(i->getCourse()) <<endl;
		/*cout << i->getCourse()->getCourseNo() << endl;*/
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
				return "Grade: " + to_string(i->getGrade()) + " ,gg passed W gamer";
			}
			else {
				return "Grade: " + to_string(i->getGrade()) + " ,L rip lol";
			}
		}
	}
	return "Bro hasn't completed the course";
}
//void Transcript::display() {
//	cout << "   >Transcript for: " << this->student->getName() << endl;
//	for (auto i : this->entries) {
//		cout << "    +Section: " << i->getSection()->getSectionNo() << ", Grade: " << i->getGrade() << endl;
//	}
//	if (this->entries.empty()) {
//		cout << "    -No entries found." << endl;
//	}
//}
//TranscriptEntry

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
TranscriptEntry::TranscriptEntry(float grade, Section* section) {
	this->setGrade(grade);
	this->setSection(section);
}
int main() {
/*
public class MainTest {
	public static void main(String[] args) {
		Course oop = new Course("MTH10407", "OOP", 4);
		Section oop23_24_3 = oop.scheduleSection("MTH10407-24-25-2", "Tue", "8:00AM", "F202", 100);
		Student alice = new Student("001", "Alice", "Maths", "Bachelor");
		oop23_24_3.enroll(alice);
		oop23_23_3.postGrade(alice, 9);

		Course dsa = new Course("MTH10405", "DSA", 4);
		Section dsa23_24_3 = dsa.scheduleSection("MTH10405-24-25-2", "Wed", "8:00AM", "E202A", 100);
		dsa23_24_3.enroll(alice);
		dsa23_23_3.postGrade(alice, 8);

		alice.printTranscript();
	}
}
*/
	/* test case lab
	Course* oop = new Course("MTH10407", "OOP", 4);
	Section* oop23_24_3 = new Section("MTH10407-24-25-2", "Tue", "8:00AM", "F202", 100);
	oop->scheduleSection(oop23_24_3);
	Student* alice = new Student("001", "Alice", "Maths", "Bachelor");
	oop23_24_3->enroll(alice);
	oop23_24_3->postGrade(alice, 4);
	Course* dsa = new Course("MTH10405", "DSA", 4);
	Section* dsa23_24_3 = new Section("MTH10405-24-25-2", "Wed", "8:00AM", "E202A", 100);
	dsa->scheduleSection(dsa23_24_3);
	dsa23_24_3->enroll(alice);
	dsa23_24_3->postGrade(alice, 8);
	alice->displayAll();
	//alice->getTranscript()->display();
	*/
	

	//Students:
	Student* A1 = new Student("001", "NPC1", "Comsci Maths", "Bachelor");
	Student* A2 = new Student("002", "NPC2", "App Maths", "Bachelor");
	Student* A3 = new Student("003", "NPC3", "App Maths", "Bachelor");
	Student* A4 = new Student("004", "NPC4", "Maths", "Bachelor");
	Student* A5 = new Student("005", "NPC5", "Comsci Maths", "Bachelor");
	//Professors:
	Professor* B1 = new Professor("001", "BOSS1", "Dr.STONE", "Comsci");
	Professor* B2 = new Professor("002", "BOSS2", "Dr.STRANGE", "Comsci");
	Professor* B3 = new Professor("003", "BOSS3", "Dr.COKE", "Maths");

	//Schedule of Classes:
	ScheduleOfClasses* schedule = new ScheduleOfClasses("2024 - 2045");
	//Courses:
	Course* OOP = new Course("MTH10407", "OOP", 4);
	Course* DSA = new Course("MTH10405", "DSA", 4);
	Course* AI = new Course("MTH10408", "AI", 4);
	Course* CSDL = new Course("MTH69420", "CSDLoz", 4);
	//Prerequisites:
	OOP->addPrerequisite(DSA);
	//Sections:
	Section* OOP_1 = new Section("MTH10407-24-25-1", "Tue", "8:00AM", "F102", 60, schedule, OOP);
	Section* OOP_2 = new Section("MTH10407-24-25-2", "Wed", "8:00AM", "F202", 80, schedule, OOP);
	Section* DSA_1 = new Section("MTH10405-24-25-1", "Tue", "8:00AM", "F402", 60, schedule, DSA);
	Section* AI_1 = new Section("MTH10408-24-25-1", "Thu", "8:00AM", "F602", 100, schedule, AI);
	Section* CSDL_1 = new Section("MTH69420-24-25-1", "Fri", "8:00AM", "F702", 120, schedule, CSDL);
	//Professors agree to teach:
	B1->agreeToTeach(OOP_1);
	B1->agreeToTeach(OOP_2);
	B2->agreeToTeach(DSA_1);
	B3->agreeToTeach(AI_1);
	B3->agreeToTeach(CSDL_1);
	//Enroll
	DSA_1->enroll(A1); 
	DSA_1->enroll(A2); 
	DSA_1->enroll(A3); 
	DSA_1->enroll(A4); 
	DSA_1->enroll(A5);
	DSA_1->postGrade(A1, 8);
	DSA_1->postGrade(A2, 7);
	DSA_1->postGrade(A3, 3);
	DSA_1->postGrade(A4, 4);
	DSA_1->postGrade(A5, 10);

	OOP_1->enroll(A1);
	OOP_2->enroll(A2);
	OOP_1->enroll(A3);
	OOP_2->enroll(A4);
	OOP_1->enroll(A5);

	// Enroll a few students in AI and CSDL
	AI_1->enroll(A1);
	AI_1->enroll(A2);
	AI_1->enroll(A4);
	AI_1->enroll(A5);
	CSDL_1->enroll(A3);
	CSDL_1->enroll(A4);
	CSDL_1->enroll(A5);
	return 0;
}