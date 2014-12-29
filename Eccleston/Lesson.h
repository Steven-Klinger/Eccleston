#ifndef LESSON_H
#define LESSON_H

#include <iostream>
using namespace std;

class Lesson
{

public:
	Lesson(string, tm, tm, int);
	Lesson(string, int);
	Lesson();

//	void addResource(Resource);
//	void addStudent(Student);
//	void addStudentMainList(Student);
//	void addStudentSecondaryList(Student);
	int checkDate(tm);
	int checkFile(string);
	int checkRepository(string);
	int checkResourceName(string);
	int checkUrl(string);
	tm getDateBegin() const { return this->dateBegin; }
	tm getDateEnd() const { return this->dateEnd; }
	int getMaxStudents() const{ return this->maxStudents; }
	string getName() const { return this->name; }
	// Resource getResource(int);
	// Resource* getResources();
	// Student getStudentSecondaryList(int);
	// Student* getStudents();
//	Teacher getTeacher() { return teacher; }
	// int isMainListFull();
	// int isStudentMainList(Student);
	int isValidated() const { return validate; }
	// void removeResource(Resource);
	// void removeStudent(Student);
	// void removeStudentMainList(Student);
	// void removeStudentSecondaryList(Student);
	void setDateBegin(tm dateBegin) { this->dateBegin = dateBegin; }
	void setDateEnd(tm dateEnd) { this->dateEnd = dateEnd; }
	void setMaxStudent(int maxStudent) { this->maxStudents = maxStudent; }
	void setName(string name) { this->name = name; }
//	void setTeacher(Teacher teacher) { this->teacher = teacher; }
	void setValidate(int validate) { this->validate = validate; }

	~Lesson();

protected:
	string name;
	tm dateBegin;
	tm dateEnd;
	int validate;
	int maxStudents;
//	vector<Student> MainListUsers;
//	vector<Student> SecondaryListUsers;
//	vector<Resource> listResources;
//	Teacher teacher;
};

#endif