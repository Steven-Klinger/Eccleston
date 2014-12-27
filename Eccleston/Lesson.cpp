#include "Lesson.h"
#include <iostream>
#include <string>
#include <ctime>

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
