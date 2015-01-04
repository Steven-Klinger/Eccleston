#include "Teacher.h"

Teacher::Teacher() : User() {
	this->firstName = "";
	this->name = "";
	this->password = "";
	this->login = "";
	this->email = "";
}

Teacher::Teacher(string name, string firstName, string login, string password, string email, ModelEccleston* model) : User(name, firstName,
	login, password, email, model, 1)
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
void Teacher::addLesson(Lesson* lesson){
	this->listLesson.push_back(lesson);
}

void Teacher::addNotification(Lesson* lesson, bool validated)
{
	if (validated) {
		this->listNotification.push_back(Notification("Lesson validated", "Lesson " + lesson->getName() + " is validated", tm()));
	}
	else {
		this->listNotification.push_back(Notification("Lesson rejected", "Lesson " + lesson->getName() + " is rejected", tm()));
	}
}

Lesson* Teacher::getLesson(int index){
	return this->listLesson.at(index);
}

vector<Lesson*> Teacher::getLessons(){
	return this->listLesson;
}

void Teacher::setLesson(int i, Lesson* newLesson){
	listLesson.at(i) = newLesson;
}
