#include "Student.h"


//A faire après création du modèle 


Student::Student(string firstName, string Name, string password, string login, string email) : User(firstName,Name,
				password,login,email)
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

// comprends plus cette fonction *Erwan
void Student::addLesson(string name, tm date1, tm date2){
	
}

void Student::addNotification(Lesson lesson){
	string subject = "Notification Lesson";
	string message = "add in Lesson " + lesson.getName();
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

void Student::addNotification(Resource res){
	string subject = "Notification On resource";
	string message = "add of Ressource " + res.getName();
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

//à compléter
void Student::addNotification(Work* work){
	string subject = "Notification of Work";
	string message = "add of work " ;
	Notification notif = Notification(subject, message, tm());
	this->listNotification.push_back(notif);
}

vector<Lesson> Student::getLessons(){
	return listLessons;
}

int Student::getUserType(){
	return 1; // 1 pour student ?
}

Work* Student::getWork(int i){
	return listWork.at(i);
}

void Student::setWork(int i, Work* nWork){
	listWork.at(i) =  nWork;
}