#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include "Work.h"
#include "ResourceFile.h"
using namespace std;

class Repository : public ResourceFile{
public:
	Repository(string, int, string, tm);
	~Repository();
	void addWork(Work, Student);
	int checkFile(string);
	int checkResourceFileName(string);
	string getPath();
	int getTypeResourceFile();
	vector<Work> getWorks();
	void removeWork(Student);
	void setPath(string);

protected:
	string path;
	tm dateEnd;
	vector<Work> listWorks;
};

#endif
