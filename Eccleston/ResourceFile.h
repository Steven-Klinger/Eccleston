#ifndef RESOURCE_FILE_H
#define RESOURCE_FILE_H

#include <iostream>
using namespace std;

class ResourceFile{
public:
	ResourceFile(string, int);
	
	tm getDateCreation() const{ return this->dateCreation; }
	string getName() const{ return this->name; }
	int getTypeResourceFile();
	int isVisible() const{ return this->visible; }
	void setDateCreation(tm);
	void setName(string);
	void setVisible(int);
	~ResourceFile();

protected:
	string name;
	tm dateCreation;
	int visible;
};

#endif