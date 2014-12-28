#include "ModelEccleston.h"

/*
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
	
}

void ModelEccleston::addUser(User user){

}

bool ModelEccleston::checkDate(tm date1, tm date2){
	return true;
}

bool ModelEccleston::checkEMailAvailable(string email){
	return true;
}

bool ModelEccleston::checkLesson(string lesson){
	return true;
}

bool ModelEccleston::checkLogin(string login){
	return true;
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
		if (listUsers[i].getUserType == 1){
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
		if ((string)this->listUsers[i].getLogin == "login"){
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
*/