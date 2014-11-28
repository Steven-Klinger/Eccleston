#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>
#include <ctime>

using namespace std;


class Student: public User
{

public:
	Student(string,string,string,string,string);
	~Student();
	void addLesson(string, tm, tm);
	//void addNotification(Lesson); // à compléter plus tard
	//void addNotification(Ressource); // à compléter plus tard
	//void addNotification(Work); // à compléter plus tard
	//Lesson[] getLessons(); // à compléter plus tard
	int getUserType();
	//Work getWork(int); // à compléter plus tard
	//void setWork(int,Work); // à compléter plus tard

};

#endif