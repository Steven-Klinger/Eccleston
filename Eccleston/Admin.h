#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Lesson.h"
#include "ResourceFile.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <iostream>
#include <ctime>

using namespace std;

class Admin : public User
{
public:
	Admin(string firstName, string name, string password, string login, string eMail, ModelEccleston* model);
	~Admin();
	void addNotification(Lesson);
	int getUserType();
};
#endif
