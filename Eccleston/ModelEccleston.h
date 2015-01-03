#pragma once

#ifndef MODELECCLESTON_H
#define MODELECCLESTON_H

#include "User.h"
#include "Lesson.h"
#include "ResourceFile.h"
#include "Notification.h"
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"
//#include "Work.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>  // std::for_each


class ModelEccleston
{
public:

	ModelEccleston();
	~ModelEccleston();
	void addLesson(Lesson* lesson);
	void addUser(Admin* user);
	void addUser(Teacher* user);
	void addUser(Student* user);
	bool checkDate(tm date1, tm date2);
	bool checkEMailAvailable(string email);
	bool checkLesson(string lesson);
	bool checkLogin(string login, string password);
	bool checkLoginAvailable(string login);
	bool checkNameAvailable(string s1, string s2);
	Admin* getAdmin();
	User getCurrentUser();
	Admin* getCurrentAdmin() { return currentAdmin; }
	Teacher* getCurrentTeacher() { return currentTeacher; }
	Student* getCurrentStudent() { return currentStudent; }
	std::vector<Lesson*> getOpenLesson();
	User* getUser(int i);
	User* getUserByLogin(string login);
	Admin* getAdminByLogin(string login);
	Teacher* getTeacherByLogin(string login);
	Student* getStudentByLogin(string login);
	std::vector<Lesson*> getWaitingLessons();
	vector<User*> getUsers(); // non presente dans le contrat 
	void removeLesson(Lesson* lesson);
	void removeUser(Admin* user);
	void removeUser(Teacher* user);
	void removeUser(Student* user);
	void setCurrentUser(Admin* admin) { this->currentAdmin = admin; this->currentUser = *admin; }
	void setCurrentUser(Teacher* teacher) { this->currentTeacher = teacher; this->currentUser = *teacher; }
	void setCurrentUser(Student* student) { this->currentStudent = student; this->currentUser = *student; }

private:
	User currentUser;
	Admin* currentAdmin;
	Teacher* currentTeacher;
	Student* currentStudent;
	std::vector<Admin*> listAdmin;
	std::vector<Teacher*> listTeacher;
	std::vector<Student*> listStudent;
	std::vector<Lesson*> listLessons;
};

#endif
