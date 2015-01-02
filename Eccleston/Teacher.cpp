#include "Teacher.h"

Teacher::Teacher() : User() {
	this->firstName = "";
	this->name = "";
	this->password = "";
	this->login = "";
	this->email = "";
}

Teacher::Teacher(string firstName, string name, string password, string login, string email, ModelEccleston* model) : User(firstName, name,
	password, login, email, model)
{
	this->firstName = firstName;
	this->name = name;
	this->password = password;
	this->login = login;
	this->email = email;
}


Teacher::~Teacher()
{
}

//add a lesson 
void Teacher::addLesson(string name, tm date1, tm date2, int i){
	this->listLesson.push_back(Lesson(name, date1, date2, i));
}

void Teacher::addNotification(Lesson lesson, bool validated)
{
	if (validated) {
		this->listNotification.push_back(Notification("Lesson validated", "Lesson " + lesson.getName() + " is validated", tm()));
	}
	else {
		this->listNotification.push_back(Notification("Lesson rejected", "Lesson " + lesson.getName() + " is rejected", tm()));
	}
}

Lesson Teacher::getLesson(int index){
	return this->listLesson.at(index);
}

vector<Lesson> Teacher::getLessons(){
	return this->listLesson;
}

int getUserType(){
	return 1;
}

void Teacher::setLesson(int i, Lesson newLesson){
	listLesson.at(i) = newLesson;
}