#include "Lesson.h"
#include <iostream>
#include <string>

Lesson::Lesson(string name, int maxStudents){
	this->name = name;
	this->validate = 0;
	this->maxStudents = maxStudents;
}
