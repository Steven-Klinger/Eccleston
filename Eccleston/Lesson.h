#ifndef LESSON_H
#define LESSON_H

#include <iostream>
using namespace std;

class Lesson
{

public:
	Lesson(string, int);

	string getName() const { return this->name; }
	void setName(string newName) { name = newName; }
	int getMaxStudents() const{ return this->maxStudents; }
	void setMawStudent(int newMax) { maxStudents = newMax; }
	int isValidate() const{ return this->validate; }
	void setValidate(int isValidate) { validate = isValidate; }

	~Lesson();

protected:
	string name;
	int validate;
	int maxStudents;
};

#endif