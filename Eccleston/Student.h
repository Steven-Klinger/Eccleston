#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Lesson.h"
#include "Resource.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <iostream>
#include <ctime>

using namespace std;


class Student: public User
{

public:
	Student(string,string,string,string,string);
	~Student();
	void addLesson(string, tm, tm);
	void addNotification(Lesson); 
	void addNotification(Resource); 
	//void addNotification(Work);// � compl�ter plus tard
	Lesson* getLessons(); // TODO � v�rifier
	int getUserType();
	//Work getWork(int); 
	//void setWork(int,Work); // � compl�ter plus tard

};

#endif