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


void Student::addLesson(string name, tm date1, tm date2){
	
	//this->mde.
}

void Student::addNotification(Lesson lesson){

}

void Student::addNotification(Resource res){

}

//TODO après création de work
//id Student::addNotification(Work work){

//

vector<Lesson> Student::getLessons(){
	return listLessons;
}

int Student::getUserType(){
	return 1; // 0 pour student ?
}

//Work Student::getWork(int){
	//return 0;
//}

//void setWork(int,Work); // à compléter plus tard