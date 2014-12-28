#pragma once

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Lesson.h"
#include "Resource.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <iostream>
#include <ctime>

class ModelEccleston
{
public:

	ModelEccleston();
	~ModelEccleston();
	void addLesson(Lesson lesson);
	void addUser(User user);
	bool checkDate(tm date1, tm date2);
	bool checkEMailAvailable(string email);
	bool checkLesson(string lesson);
	bool checkLogin(string login);
	bool checkLoginAvailable(string login);
	bool checkNameAvailable(string s1, string s2);
	User getAdmin();
	User getCurrentUser();
	Lesson* getOpenLesson();
	User getUser(int i);
	User getUserByLogin(string login);
	Lesson* getWaitingLessons();
	void removeLesson(Lesson lesson);
	void removeUser(User user);
	void setUser(int id, User user);

private:
	User currentUser;
	User* listUsers;
	Lesson* listLesson;
};

#endif
