#include "ModelEccleston.h"
#include <istream>
#include <fstream>
#include <string> // necesaire pour getline
#include <sstream>
//constructeur
ModelEccleston::ModelEccleston()
{
	// fill the list of users with data in users.txt file
/*	string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
	std::ifstream file(path.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				this->listUsers.push_back(User(name, firstName, login, password, eMail, this, -1));
			}
		}
		file.close(); //close the file
	}
*/	
	this->currentUserType = -1;
}


ModelEccleston::~ModelEccleston()
{
}

void ModelEccleston::addLesson(Lesson* lesson){
	listLessons.push_back(lesson);
}

void ModelEccleston::addUser(Admin* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listAdmin.push_back(user);
		string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){ // if file exists

			cout << "insertion fichier users.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close(); //close the file
		}
		else {
			cout << "insertion fichier users.txt PAS ok" << endl;
		}
	}
}

void ModelEccleston::addUser(Teacher* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listTeacher.push_back(user);
		string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){ // if file exists

			cout << "insertion fichier users.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close(); //close the file
		}
		else {
			cout << "insertion fichier users.txt PAS ok" << endl;
		}
	}
}

void ModelEccleston::addUser(Student* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listStudent.push_back(user);
		string path = "C://Users/erwan/Documents/Eccleston/projetEccleston/Debug/users.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){ // if file exists

			cout << "insertion fichier users.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close(); //close the file
		}
		else {
			cout << "insertion fichier users.txt PAS ok" << endl;
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
	for (User* us : this->getUsers()){ // foreach en c++
		if (us->getEmail() == email){
			emailCheck = false;
		}
	}
	return emailCheck;
}

/* retrun true if the lesson is not already in listLesson*/
bool ModelEccleston::checkLesson(string lesson){
	bool lessonCheck = true;
	for (Lesson* les : listLessons){
		if (les->getName() == lesson){
			lessonCheck = false;
		}
	}
	return lessonCheck;
}

/* return true if the login in parameter is in listUsers*/
bool ModelEccleston::checkLogin(string login, string password){
	bool loginCheck = false;
	for (User* us : this->getUsers()){
		if (us->getLogin() == login & us->getPassword() == password){
			loginCheck = true;
		}
	}
	return loginCheck;
}

/* return true if the login is available*/
bool ModelEccleston::checkLoginAvailable(string login){
	bool loginCheck = true;
	for (User* us : this->getUsers()){
		if (us->getLogin() == login){
			loginCheck = false;
		}
	}
	return loginCheck;
}

//TODO elle fait quoi cette fonction déjà ?
bool ModelEccleston::checkNameAvailable(string s1, string s2){
	return true;
}


Admin* ModelEccleston::getAdmin(){
	return listAdmin.at(0);
}

vector<Lesson*> ModelEccleston::getOpenLesson(){
	return this->listLessons; // A MODIFIER !!!
}

vector<User*> ModelEccleston::getUsers(){
	vector<User*> listUsers;
	for (Admin* us : listAdmin){
		listUsers.push_back(us);
	}
	for (Teacher* us : listTeacher){
		listUsers.push_back(us);
	}
	for (Student* us : listStudent){
		listUsers.push_back(us);
	}
	return listUsers;
}

User* ModelEccleston::getUser(int i){
	return this->getUsers().at(i);
}

User* ModelEccleston::getUserByLogin(string login){
	int i = 0;
	User* usr = NULL;
	for (User* us : this->getUsers()){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}

Admin* ModelEccleston::getAdminByLogin(string login){
	int i = 0;
	Admin* usr = NULL;
	for (Admin* us : listAdmin){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}

Teacher* ModelEccleston::getTeacherByLogin(string login){
	int i = 0;
	Teacher* usr = NULL;
	for (Teacher* us : listTeacher){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}

Student* ModelEccleston::getStudentByLogin(string login){
	int i = 0;
	Student* usr = NULL;
	for (Student* us : listStudent){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}

vector<Lesson*> ModelEccleston::getWaitingLessons(){
	vector<Lesson*> waitingLesson;
	for (Lesson* les : listLessons) {
		if (!les->isValidated()) {
			waitingLesson.push_back(les);
		}
	}
	return waitingLesson;
}

void ModelEccleston::removeLesson(Lesson* lesson){
	int i = 0;
	if (listLessons.at(0)->getName() == lesson->getName()){
		listLessons.erase(listLessons.begin() + 0);
	}
	else {
		for (unsigned int i = 1; i < listLessons.size(); i++){
			if (listLessons.at(i)->getName() == lesson->getName()){
				listLessons.erase(listLessons.begin() + i);
			}
		}
	}

}


void ModelEccleston::removeUser(Admin* user){
	int i = 0;
	if (listAdmin.at(0)->getLogin() == user->getLogin()){
		listAdmin.erase(listAdmin.begin() + 0);
	}
	else {
		for (unsigned int i = 1; i < listAdmin.size(); i++){
			if (listAdmin.at(i)->getLogin() == user->getLogin()){
				listAdmin.erase(listAdmin.begin() + i);
			}
		}
	}
}

void ModelEccleston::removeUser(Teacher* user){
	int i = 0;
	if (listTeacher.at(0)->getLogin() == user->getLogin()){
		listTeacher.erase(listTeacher.begin() + 0);
	}
	else {
		for (unsigned int i = 1; i < listTeacher.size(); i++){
			if (listTeacher.at(i)->getLogin() == user->getLogin()){
				listTeacher.erase(listTeacher.begin() + i);
			}
		}
	}
}

void ModelEccleston::removeUser(Student* user){
	int i = 0;
	if (listStudent.at(0)->getLogin() == user->getLogin()){
		listStudent.erase(listStudent.begin() + 0);
	}
	else {
		for (unsigned int i = 1; i < listStudent.size(); i++){
			if (listStudent.at(i)->getLogin() == user->getLogin()){
				listStudent.erase(listStudent.begin() + i);
			}
		}
	}
}

