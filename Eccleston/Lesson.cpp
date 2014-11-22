#include<iostream>

class User
{

protected :
	char* name;
	int validate;
	int maxStudents;

public:
	char* getName() const { return this->name; }
	void setName(char* newName) {name = newName; }
	int getMaxStudents() const{ return this->maxStudents; }
	void setMawStudent(int newMax) {maxStudents = newMax; }
	int isValidate() const{ return this->validate; }
	void setValidate(int isValidate) {validate = isValidate; }
};
