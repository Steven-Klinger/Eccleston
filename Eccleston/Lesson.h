#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Lesson
{

public:
	Lesson();

	char* getName() const { return this->name; }
	void setName(char* newName) { name = newName; }
	int getMaxStudents() const{ return this->maxStudents; }
	void setMawStudent(int newMax) { maxStudents = newMax; }
	int isValidate() const{ return this->validate; }
	void setValidate(int isValidate) { validate = isValidate; }

	~Lesson();

protected:
	char* name;
	int validate;
	int maxStudents;
};

#endif