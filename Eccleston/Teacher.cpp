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

void addLesson(string name, tm date1, tm date2, int i){

}

void addNotification(Lesson lesson, bool b1){

}

//vector<Lesson> getLesson(){
	//return 0;
//}

int getUserType(){
	return 2;
}

void setLesson(int i, Lesson newLesson){

}