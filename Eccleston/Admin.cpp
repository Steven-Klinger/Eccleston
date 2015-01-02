#include "Admin.h"


Admin::Admin(string firstName, string name, string password, string login, string eMail, ModelEccleston* model) : User(firstName, name,
	password, login, email, model)
{
	this->firstName = firstName;
	this->name = name;
	this->password = password;
	this->login = login;
	this->email = eMail;
}


Admin::~Admin()
{
}

void Admin::addNotification(Lesson lesson){
	this->listNotification.push_back(Notification("Add of Lesson", "Lesson " + lesson.getName() + " requires your validation", tm()));
}

int Admin::getUserType(){
	return 0;
}