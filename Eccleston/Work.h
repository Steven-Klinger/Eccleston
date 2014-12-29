#ifndef WORK_H
#define WORK_H
#include <iostream>

using namespace std;

class Work{
public:
	Work(string, string);
	int getMark();
	Student getStudent();
	int getTypeResource();
	void setMark(int);

protected:
	int corrected;
	int mark;
};
