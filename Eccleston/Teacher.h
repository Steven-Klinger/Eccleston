#pragma once
#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Lesson.h"
#include "Resource.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <iostream>
#include <ctime>

class Teacher : public User
{
public:
	Teacher(string firstName, string name, string password, string login, string email);
	~Teacher();
	void addLesson(string name, tm date1, tm date2, int i); // c'est pourquoi déjà le  i?
	void addNotification(Lesson lesson, bool b1);
	Lesson* getLesson();
	int getUserType();
	void setLesson(int i, Lesson newLesson);
};

#endif