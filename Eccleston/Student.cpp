#include "Student.h"


//A faire après création du modèle 


Student::Student(string firstName, string Name, string password, string login, string email, ModelEccleston* model) : User(firstName,Name,
				password,login,email, model, 2)
{
	this->firstName = firstName;
	this->name = Name;
	this->password = password;
	this->login = login;
	this->email = email;
}

Student::Student() : User(){
	this->firstName = "";
	this->name = "";
	this->password = "";
	this->login = "";
	this->email = "";
}

Student::~Student()
{
}

void Student::addLesson(Lesson* lesson){
	listLessons.push_back(lesson);
}

void Student::addNotification(Lesson* lesson){
	string subject = "Add in main list";
	string message = "You are in the main list for " + lesson->getName();
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

void Student::addNotification(ResourceFile res, Lesson* les){
	string subject = "Add ResourceFile";
	string message = "Add of Ressource " + res.getName() + " in " + les->getName();
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

void Student::addNotification(Work* work){
	string subject = "Your work are marked";
	string message = "Your have [work mark] for your work [name work]";
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

vector<Lesson*> Student::getLessons(){
	return listLessons;
}

Work* Student::getWork(int i){
	return listWork.at(i);
}

void Student::setWork(int i, Work* nWork){
	listWork.at(i) =  nWork;
}