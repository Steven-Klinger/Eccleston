#include "Teacher.h"

Teacher::Teacher() : User() {
	this->firstName = "";
	this->name = "";
	this->password = "";
	this->login = "";
	this->email = "";
}

Teacher::Teacher(string firstName, string name, string password, string login, string email) : User(firstName, name,
	password, login, email)
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
//comprends pas cette fonction
void addNotification(Lesson lesson, bool b1){

}

vector<Lesson> Teacher::getLesson(){
	return this->listLesson;
}

int getUserType(){
	return 2;
}

void Teacher::setLesson(int i, Lesson newLesson){
	listLesson.at(i) = newLesson;
}