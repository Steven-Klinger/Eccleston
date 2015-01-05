#include "ModelEccleston.h"
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h> 
#include <windows.h>

const string path = "C:/Users/Public/Eccleston";

ModelEccleston::ModelEccleston()
{
	CreateDirectory((LPCSTR)path.c_str(), NULL);

	string pathStu = path + "/students~.txt";
	string pathStuOld = path + "/students.txt";
	rename(pathStuOld.c_str(), pathStu.c_str());
	remove(pathStuOld.c_str());
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Student* pUser = new Student(name, firstName, login, password, eMail, this);
				this->addUser(pUser);
			}
		}
		file.close();
	}
	remove(pathStu.c_str());
	string pathAd = path + "/admins~.txt";
	string pathAdOld = path + "/admins.txt";
	rename(pathAdOld.c_str(), pathAd.c_str());
	remove(pathAdOld.c_str());
	std::ifstream file2(pathAd.c_str(), ios::in);
	if (file2){ //
		string line;
		while (getline(file2, line)){
			istringstream iss(line);
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Admin* pUser = new Admin(name, firstName, login, password, eMail, this);
				this->addUser(pUser);
			}
		}
		file2.close();
	}
	remove(pathAd.c_str());
	string pathTeacher = path + "/teachers~.txt";
	string pathTeacherOld = path + "/teachers.txt";
	rename(pathTeacherOld.c_str(), pathTeacher.c_str());
	remove(pathTeacherOld.c_str());
	std::ifstream file3(pathTeacher.c_str(), ios::in);
	if (file3){ // if file exists
		string line;
		while (getline(file3, line)){
			istringstream iss(line);
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (this->checkLoginAvailable(login)){
				Teacher* pUser = new Teacher(name, firstName, login, password, eMail, this);
				this->addUser(pUser);
			}
		}
		file3.close();
	}
	remove(pathTeacher.c_str());
	string pathLesson = path + "/lessons~.txt";
	string pathLessonOld = path + "/lessons.txt";
	rename(pathLessonOld.c_str(), pathLesson.c_str());
	remove(pathLessonOld.c_str());
	std::ifstream file4(pathLesson.c_str(), ios::in);
	if (file4){
		string line;
		while (getline(file4, line)){
			istringstream iss(line); // creat a separator for line
			string name, teacherLog;
			int nbrMax, validated;
			iss >> name >> teacherLog >> nbrMax >> validated;
			if (this->checkLesson(name)){
				Teacher* teacher = this->getTeacherByLogin(teacherLog);
				if (teacher != NULL){
					Lesson* pLesson = new Lesson(name, teacher, nbrMax);
					pLesson->setValidate(validated);
					this->addLesson(pLesson);
				}
			}
		}
		file4.close();
	}
	remove(pathLesson.c_str());

	this->currentUserType = -1;
}

ModelEccleston::~ModelEccleston()
{
}

void ModelEccleston::addLesson(Lesson* lesson){
	if (this->checkLesson(lesson->getName())){
		listLessons.push_back(lesson);
		string name = path + "/lessons.txt";
		std::ofstream file(name.c_str(), ios::out | ios::app);
		if (file){
			string  name, teacher;
			int nbrMax, validates;
			name = lesson->getName();
			teacher = lesson->getTeacher()->getLogin();
			nbrMax = lesson->getMaxStudents();
			validates = lesson->isValidated();
			file << name << " " << teacher << " " << nbrMax << " " << validates << " " << endl;
			file.close();
		}
		else {
			
		}
	}
}

void ModelEccleston::addUser(Admin* user){
	if (this->checkLoginAvailable(user->getLogin())){
		listAdmin.push_back(user);
		string name = path + "/admins.txt";
		std::ofstream file(name.c_str(), ios::out | ios::app);
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
		string name = path + "/teachers.txt";
		std::ofstream file(name.c_str(), ios::out | ios::app);
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
		string name = path + "/students.txt";
		std::ofstream file(name.c_str(), ios::out | ios::app);
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
	if (date1.tm_year > date2.tm_year){
		return false;
	}
	else if (date1.tm_year == date2.tm_year){
		if (date1.tm_mon > date2.tm_mon){
			return false;
		}
	}
	else{
		if (date1.tm_mday > date2.tm_mday){
			return false;
		}
	}
	return true;
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
	for (Lesson* les : this->listLessons){
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
	for (Admin* us : this->listAdmin){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}
Teacher* ModelEccleston::getTeacherByLogin(string login){
	int i = 0;
	Teacher* usr = NULL;
	std::vector<Teacher*> list = this->listTeacher;
	for (Teacher* us : list){
		if (us->getLogin() == login){
			usr = us;
		}
	}
	return usr;
}
Student* ModelEccleston::getStudentByLogin(string login){
	int i = 0;
	Student* usr = NULL;
	for (Student* us : this->listStudent){
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
	string pathStu = path + "/lessons.txt";
	string buffer;
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string name,teacher,strNbrMax;
			iss >> name >> teacher >> strNbrMax;
			if (!(lesson->getName() == name)){
				buffer += name + " " + teacher + " " + strNbrMax + '\n';
			}
		}
		file.close(); //close the file
	}
	std::ofstream file2(pathStu.c_str(), ios::out);
	if (file2){ // if file exists
		file2 << buffer;
		file.close(); //close the file
	}
	else {
		
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
	string pathStu = path + "/admins.txt";
	string buffer;
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (!(user->getLogin() == login)){
				buffer += name + " " + firstName + " " + login + " " + password + " " + eMail + '\n';
			}
		}
		file.close(); //close the file
	}
	std::ofstream file2(pathStu.c_str(), ios::out);
	if (file2){ // if file exists
		file2 << buffer;
		file.close(); //close the file
	}
	else {
		cout << "insertion fichier teachers.txt PAS ok" << endl;
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
	string pathStu = path + "/teachers.txt";
	string buffer;
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (!(user->getLogin() == login)){
				buffer += name + " " + firstName + " " + login + " " + password + " " + eMail + '\n';
			}
		}
		file.close(); //close the file
	}
	std::ofstream file2(pathStu.c_str(), ios::out);
	if (file2){ // if file exists
		file2 << buffer;
		file.close(); //close the file
	}
	else {
		cout << "insertion fichier teachers.txt PAS ok" << endl;
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
	string pathStu = path + "/students.txt";
	string buffer;
	std::ifstream file(pathStu.c_str(), ios::in);
	if (file){ // if file exists
		string line;
		while (getline(file, line)){
			istringstream iss(line); // creat a separator for line
			string firstName, name, login, password, eMail;
			iss >> name >> firstName >> login >> password >> eMail;
			if (!(user->getLogin() == login)){
				buffer += name + " " + firstName + " " + login + " " + password + " " + eMail + '\n';
			}
		}
		file.close(); //close the file
	}
	std::ofstream file2(pathStu.c_str(), ios::out);
	if (file2){ // if file exists
		file2 << buffer;
		file.close(); //close the file
	}
	else {
		cout << "insertion fichier teachers.txt PAS ok" << endl;
	}
}
