#include "Admin.h"


Admin::Admin(string name, string firstName, string login, string password, string eMail, ModelEccleston* model) : User(name, firstName,
	login, password, eMail, model, 0)
{
	this->firstName = firstName;
	this->name = name;
	this->password = password;
	this->login = login;
	this->email = eMail;
}

Admin::Admin() : User()
{
	this->firstName = "";
	this->name = "";
	this->password = "";
	this->login = "";
	this->email = "";
}

Admin::~Admin()
{
}

void Admin::addNotification(Lesson lesson){
	this->listNotification.push_back(Notification("Add of Lesson", "Lesson " + lesson.getName() + " requires your validation", tm()));
}
