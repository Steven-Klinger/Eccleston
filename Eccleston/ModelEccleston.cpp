#include "ModelEccleston.h"
#include <istream>
#include <fstream>
#include <string> 
#include <sstream>

ModelEccleston::ModelEccleston()
{
	// fill the list of users with data in users.txt file
	string pathStu = "students.txt";
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){ 
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Student* pUser = new Student(name, firstName, login, password, eMail, this);
				this->listStudent.push_back(pUser);
			}
		}
		file.close();
	}
	
	string pathAd = "admins.txt";
	std::ifstream file2(pathAd.c_str(), ios::in);
	if (file2){ // 
		string line;
		while (getline(file2, line)){
			istringstream iss(line);
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Admin* pUser = new Admin(name, firstName, login, password, eMail, this);
				this->listAdmin.push_back(pUser);
			}
		}
		file2.close();
	}

	string pathTeacher = "/teachers.txt";
	std::ifstream file3(pathTeacher.c_str(), ios::in);
	if (file3){ // if file exists
		string line;
		while (getline(file3, line)){
			istringstream iss(line);
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Teacher* pUser = new Teacher(name, firstName, login, password, eMail, this);
				this->listTeacher.push_back(pUser);
			}
		}
		file3.close();
	}

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
		string path = "admins.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){ 

			cout << "insertion fichier admins.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close();
		}
		else {
			cout << "insertion fichier admins.txt PAS ok" << endl;
		}
	}
}

void ModelEccleston::addUser(Teacher* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listTeacher.push_back(user);
		string path = "teachers.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){

			cout << "insertion fichier teachers.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close();
		}
		else {
			cout << "insertion fichier teachers.txt PAS ok" << endl;
		}
	}
}

void ModelEccleston::addUser(Student* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listStudent.push_back(user);
		string path = "students.txt";
		std::ofstream file(path.c_str(), ios::out | ios::app);
		if (file){

			cout << "insertion fichier teachers.txt ok" << endl;

			string firstName, name, login, password, eMail;
			name = user->getName();
			firstName = user->getFirstName();
			login = user->getLogin();
			password = user->getPassword();
			eMail = user->getEmail();
			file << name << " " << firstName << " " << login << " " << password << " " << eMail << " " << endl;
			file.close();
		}
		else {
			cout << "insertion fichier teachers.txt PAS ok" << endl;
		}
	}
}

bool ModelEccleston::checkDate(tm date1, tm date2){
	return (date1.tm_year + date1.tm_mon + date1.tm_mday + date1.tm_hour + date1.tm_min + date1.tm_sec) <
		(date2.tm_year + date2.tm_mon + date2.tm_mday + date2.tm_hour + date2.tm_min + date2.tm_sec);
}


bool ModelEccleston::checkEMailAvailable(string email){
	bool emailCheck = true;
	for (User* us : this->getUsers()){
		if (us->getEmail() == email){
			emailCheck = false;
		}
	}
	return emailCheck;
}


bool ModelEccleston::checkLesson(string lesson){
	bool lessonCheck = true;
	for (Lesson* les : listLessons){
		if (les->getName() == lesson){
			lessonCheck = false;
		}
	}
	return lessonCheck;
}


bool ModelEccleston::checkLogin(string login, string password){
	bool loginCheck = false;
	for (User* us : this->getUsers()){
		if (us->getLogin() == login & us->getPassword() == password){
			loginCheck = true;
		}
	}
	return loginCheck;
}

bool ModelEccleston::checkLoginAvailable(string login){
	bool loginCheck = true;
	for (User* us : this->getUsers()){
		if (us->getLogin() == login){
			loginCheck = false;
		}
	}
	return loginCheck;
}

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

