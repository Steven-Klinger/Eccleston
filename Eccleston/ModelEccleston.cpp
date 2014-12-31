#include "ModelEccleston.h"
#include <istream>
#include <fstream>
#include <string> // necesaire pour getline
#include <sstream>
//constructeur
ModelEccleston::ModelEccleston()
{
	// fill the list of users with data in users.txt file
	string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
	std::ifstream file(path.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (!this->checkLogin(login)){
				this->listUsers.push_back(User(name, firstName, login, password, eMail));
			}
		}
		file.close(); //close the file
	}
	
}


ModelEccleston::~ModelEccleston()
{
}

void ModelEccleston::addLesson(Lesson lesson){
	listLessons.push_back(lesson);
}

void ModelEccleston::addUser(User user){
	if (!this->checkLogin(user.getLogin())){
		listUsers.push_back(user);
		string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){ // if file exists

			cout << "insertion fichier users.tx ok" << endl;

			string firstName, name, login, password, eMail;
			name = user.getName();
			firstName = user.getFirstName();
			login = user.getLogin();
			password = user.getPassword();
			eMail = user.getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close(); //close the file
		}
		else {
			cout << "insertion fichier users.tx PAS ok" << endl;
		}
	}
}

bool ModelEccleston::checkDate(tm date1, tm date2){
	return (date1.tm_year + date1.tm_mon + date1.tm_mday + date1.tm_hour + date1.tm_min + date1.tm_sec) <
		(date2.tm_year + date2.tm_mon + date2.tm_mday + date2.tm_hour + date2.tm_min + date2.tm_sec);
}

/*Renvoie vrai si l'email n'est pas déjà pris */
bool ModelEccleston::checkEMailAvailable(string email){
	bool emailCheck = true;
	for(User us : listUsers){ // foreach en c++
		if (us.getEmail() == email){
			emailCheck = false;
		}
	}
	return emailCheck;
}

/* retrun true if the lesson is not already in listLesson*/
bool ModelEccleston::checkLesson(string lesson){
	bool lessonCheck = true;
	for (Lesson les : listLessons){
		if (les.getName() == lesson){
			lessonCheck = false;
		}
	}
	return lessonCheck;
}

/* return true if the login in parameter is in listUsers*/
bool ModelEccleston::checkLogin(string login){
	bool loginCheck = false;
	for (User us : listUsers){
		if (us.getLogin() == login){
			loginCheck = true;
		}
	}
	return loginCheck;
}

/* return true if the login is available*/
bool ModelEccleston::checkLoginAvailable(string login){
	bool loginCheck = true;
	for (User us : listUsers){
		if (us.getLogin() == login){
			loginCheck = false;
		}
	}
	return loginCheck;
}

//TODO elle fait quoi cette fonction déjà ?
bool ModelEccleston::checkNameAvailable(string s1, string s2){
	return true;
}


User ModelEccleston::getAdmin(){
	User admin;
	for (User us: listUsers){
		if (us.getUserType() == 1){
			admin = us;
		}
	}
	return admin;
}

User ModelEccleston::getCurrentUser(){
	return this->currentUser;
}

vector<Lesson> ModelEccleston::getOpenLesson(){
	return this->listLessons; // A MODIFIER !!!
}

vector<User> ModelEccleston::getUsers(){
	return this->listUsers;
}

User ModelEccleston::getUser(int i){
	return listUsers.at(i);
}

User ModelEccleston::getUserByLogin(string login){
	int i = 0;
	User usr;
	for (User us: listUsers){
		if (us.getLogin() == login){
			usr = us;
		}
	}
	return usr;
}

vector<Lesson> ModelEccleston::getWaitingLessons(){
	return this->listLessons; // A MODIFIER !!!
}

void ModelEccleston::removeLesson(Lesson lesson){
	int i = 0;
	if (listLessons.at(0).getName() == lesson.getName()){
		listLessons.erase(listLessons.begin() + 0);
	}
	else {
		for (int i = 1; i < listLessons.size(); i++){
			if (listLessons.at(i).getName() == lesson.getName()){
				listLessons.erase(listLessons.begin() + i);
			}
		}
	}

}


void ModelEccleston::removeUser(User user){
	int i = 0;
	if (listUsers.at(0).getLogin() == user.getLogin()){
		listUsers.erase(listUsers.begin() + 0);
	}
	else {
		for (int i = 1; i < listUsers.size(); i++){
			if (listUsers.at(i).getLogin() == user.getLogin()){
				listUsers.erase(listUsers.begin() + i);
			}
		}
	}
	
}

void ModelEccleston::setUser(int id, User user){

}
