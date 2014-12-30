#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Lesson.h"
#include "Resource.h"
#include "Notification.h"
//TODO #include "Work.h"
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;


class Student: public User
{

public:
	Student(string,string,string,string,string);
	Student();
	~Student();
	void addLesson(string, tm, tm);
	void addNotification(Lesson); 
	void addNotification(Resource); 
	//void addNotification(Work);// à compléter plus tard
	vector<Lesson> getLessons(); // TODO à vérifier
	int getUserType();
	//Work getWork(int); 
	//void setWork(int,Work); // à compléter plus tard

private:
	vector<Lesson> listLessons;
};

#endif