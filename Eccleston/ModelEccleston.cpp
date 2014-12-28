#include "ModelEccleston.h"


ModelEccleston::ModelEccleston()
{
	// un peu bloqué là
	Lesson* listLesson = new Lesson[100]; // je sais pas trop comment faire pour la taille peut etre utiliser vector
	User* listUser = new User[100];
	User currentUser;
}


ModelEccleston::~ModelEccleston()
{
}

void ModelEccleston::addLesson(Lesson lesson){
	int i = 0;
	
	while (listLesson[i].getName() != ""){ //A lesson is init by default with a "" name
		i++;
	}
	listLesson[i] = lesson;
}

void ModelEccleston::addUser(User user){
	int i = 0;

	while (listUsers[i].getName() != ""){ //A lesson is init by default with a "" name
		i++;
	}
	listUsers[i] = user;
}

bool ModelEccleston::checkDate(tm date1, tm date2){
	return (date1.tm_year+date1.tm_mon+date1.tm_mday+date1.tm_hour+date1.tm_min+date1.tm_sec) < 
		(date2.tm_year + date2.tm_mon + date2.tm_mday + date2.tm_hour + date2.tm_min + date2.tm_sec);
}

/*Renvoie vrai si l'email n'est pas déjà pris */
bool ModelEccleston::checkEMailAvailable(string email){
	int i = 0;
	bool emailCheck = true;
	for (i; i < 100; i++){
		if (listUsers[i].getEmail() == email){
			emailCheck = false;
		}
	}
	return emailCheck;
}


bool ModelEccleston::checkLesson(string lesson){
	int i = 0;
	bool lessonCheck = true;
	for (i; i < 100; i++){
		if (listLesson[i].getName() == lesson){
			lessonCheck = false;
		}
	}
	return lessonCheck;
}

bool ModelEccleston::checkLogin(string login){
	int i = 0;
	bool loginCheck = true;
	for (i; i < 100; i++){
		if (listUsers[i].getLogin() == login){
			loginCheck = false;
		}
	}
	return loginCheck;
}

bool ModelEccleston::checkLoginAvailable(string login){
	return true;
}

bool ModelEccleston::checkNameAvailable(string s1, string s2){
	return true;
}

User ModelEccleston::getAdmin(){
	int i = 0;
	User admin;
	for (i; i < 100; i++){
		if (listUsers[i].getUserType() == 1){
			admin = this->listUsers[i];
		}
	}
	return admin;
}

User ModelEccleston::getCurrentUser(){
	return this->currentUser;
}

Lesson* ModelEccleston::getOpenLesson(){
	return this->listLesson; // A MODIFIER !!!
}

User ModelEccleston::getUser(int i){
	return this->listUsers[i];
}

User ModelEccleston::getUserByLogin(string login){
	int i = 0;
	User usr;
	for (i; i < 100; i++){
		if ((string)this->listUsers[i].getLogin() == "login"){
			usr = this->listUsers[i];
		}
	}
	return usr;
}

Lesson* ModelEccleston::getWaitingLessons(){
	return this->listLesson; // A MODIFIER !!!
}

void ModelEccleston::removeLesson(Lesson lesson){
	// à faire
}

void ModelEccleston::removeUser(User user){

}

void ModelEccleston::setUser(int id, User user){

}
