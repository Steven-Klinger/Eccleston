#pragma once
#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Lesson.h"
#include "ResourceFile.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <iostream>
#include <ctime>



class Teacher : public User
{
public:
	Teacher();
	Teacher(string firstName, string name, string password, string login, string email, ModelEccleston* model);
	~Teacher();
	void addLesson(string name, tm date1, tm date2, int maxStudent); 
	void addNotification(Lesson lesson, bool validate);
	Lesson getLesson(int);
	vector<Lesson> getLessons();
	void setLesson(int i, Lesson newLesson);

protected:
	vector<Lesson> listLesson;
};

#endif
