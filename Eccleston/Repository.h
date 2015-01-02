#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include "Work.h"
#include "Resource.h"
using namespace std;

class Repository : public Resource{
public:
	Repository(string, int, string, tm);
	~Repository();
	void addWork(Work, Student);
	int checkFile(string);
	int checkResourceName(string);
	string getPath();
	int getTypeResource();
	vector<Work> getWorks();
	void removeWork(Student);
	void setPath(string);

protected:
	string path;
	tm dateEnd;
	vector<Work> listWorks;
};

#endif
