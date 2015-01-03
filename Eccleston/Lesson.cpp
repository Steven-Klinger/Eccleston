#include "Lesson.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "ResourceFile.h"
#include "Teacher.h"
#include "Student.h"

Lesson::Lesson(){
	this->name = "";
	this->dateBegin = tm();
	this->dateEnd = tm();
	this->validate = 0;
	this->maxStudents = 0;
	teacher = NULL;
}

Lesson::~Lesson(){
}

Lesson::Lesson(string name, Teacher* teacher, tm dateBegin, tm dateEnd, int maxStudents){
	this->name = name;
	this->dateBegin = dateBegin;
	this->dateEnd = dateEnd;
	this->validate = 0;
	this->maxStudents = maxStudents;
	this->teacher = teacher;
}

Lesson::Lesson(string name, Teacher* teacher, int maxStudents){
	this->name = name;
	this->dateBegin = tm();
	this->dateEnd = tm();
	this->validate = 0;
	this->maxStudents = maxStudents;
	this->teacher = teacher;
}

void Lesson::addResourceFile(ResourceFile* res) {
	this->listResourceFiles.push_back(res);
}

void Lesson::addStudent(Student* stud) {
	if (this->isMainListFull()) {
		this->addStudentSecondaryList(stud);
	}
	else {
		this->addStudentMainList(stud);
	}
}

void Lesson::addStudentMainList(Student* stud) {
	this->mainListStudent.push_back(stud);
}

void Lesson::addStudentSecondaryList(Student* stud) {
	this->secondaryListStudent.push_back(stud);
}

int Lesson::getNumbreStudent() {
	int num = 0;
	num += mainListStudent.size();
	num += secondaryListStudent.size();
	return num;
}

ResourceFile* Lesson::getResourceFile(int index) {
	return listResourceFiles.at(index);
}

vector<ResourceFile*> Lesson::getResourceFiles() {
	return listResourceFiles;
}

vector<Student*> Lesson::getStudents() {
	std::vector<Student*> listStudent;
	for (Student* stu : mainListStudent){
		listStudent.push_back(stu);
	}
	for (Student* stu : secondaryListStudent){
		listStudent.push_back(stu);
	}
	return listStudent;
}

Student* Lesson::getStudentSecondaryList(int index) {
	return this->secondaryListStudent.at(index);
}

int Lesson::isMainListFull() {
	if (this->getNumbreStudent() >= this->getMaxStudents()) {
		return 1;
	}
	else {
		return 0;
	}
}

int Lesson::isStudentMainList(Student* stud) {
	int studPresent = 0;
	for (unsigned int i = 0; i < mainListStudent.size(); i++){
		if (mainListStudent.at(i)->getName() == stud->getName() && mainListStudent.at(i)->getFirstName() == stud->getFirstName()){
			studPresent++;
		}
	}
	return studPresent;
}

void Lesson::removeResourceFile(ResourceFile* oldRes) {
	for (unsigned int i = 0; i < listResourceFiles.size(); i++){
		if (listResourceFiles.at(i)->getName() == oldRes->getName()){
			listResourceFiles.erase(listResourceFiles.begin() + i);
		}
	}
}

void Lesson::removeStudent(Student* oldStud) {
	this->removeStudentMainList(oldStud);
	this->removeStudentSecondaryList(oldStud);
}

void Lesson::removeStudentMainList(Student* oldStud) {
	int listFull = this->isMainListFull();
	int studDelete = 0;
	for (unsigned int i = 0; i < mainListStudent.size(); i++){
		if (mainListStudent.at(i)->getName() == oldStud->getName() && mainListStudent.at(i)->getFirstName() == oldStud->getFirstName()){
			mainListStudent.erase(mainListStudent.begin() + i);
			studDelete++;
		}
	}
	if (studDelete && listFull) {
		mainListStudent.push_back(secondaryListStudent.at(0));
		secondaryListStudent.erase(secondaryListStudent.begin());
	}
}

void Lesson::removeStudentSecondaryList(Student* oldStud) {
	for (unsigned int i = 0; i < mainListStudent.size(); i++){
		if (secondaryListStudent.at(i)->getName() == oldStud->getName() && secondaryListStudent.at(i)->getFirstName() == oldStud->getFirstName()){
			secondaryListStudent.erase(secondaryListStudent.begin() + i);
		}
	}
}