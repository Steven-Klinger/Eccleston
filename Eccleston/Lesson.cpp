#include "Lesson.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

//#include "Resource.h"
//#include "Teacher.h"
//#include "Student.h"

Lesson::Lesson(){
	this->name = "";
	this->dateBegin = tm();
	this->dateEnd = tm();
	this->validate = 0;
	this->maxStudents = 0;
}

Lesson::~Lesson(){
}

Lesson::Lesson(string name, tm dateBegin, tm dateEnd, int maxStudents){
	this->name = name;
	this->dateBegin = dateBegin;
	this->dateEnd = dateEnd;
	this->validate = 0;
	this->maxStudents = maxStudents;
}

Lesson::Lesson(string name, int maxStudents){
	this->name = name;
	this->validate = 0;
	this->maxStudents = maxStudents;
}
