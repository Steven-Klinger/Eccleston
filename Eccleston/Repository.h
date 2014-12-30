#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
using namespace std;

class Repository{
public:
	Repository(string, int, string, tm);
	void addWork(Work, Student);
	int checkFile(string);
	int checkResourceName(string);
	string getPath();
	int getTypeResource();
	Work[] getWorks();
	void removeWork(Student);
	void setPath(string);

protected:
	string path;
	tm dateEnd;
};

#endif
