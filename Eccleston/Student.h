#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Lesson.h"
#include "Resource.h"
#include "Notification.h"
#include <vector>
#include <iostream>
#include <ctime>

class Work;

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
	void addNotification(Work*);// à compléter plus tard
	vector<Lesson> getLessons(); // TODO à vérifier
	int getUserType();
	Work* getWork(int); 
	void setWork(int,Work*); // à compléter plus tard

private:
	vector<Lesson> listLessons;
	vector<Work*> listWork;
};

#endif