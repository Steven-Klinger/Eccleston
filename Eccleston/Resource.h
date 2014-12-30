#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
using namespace std;

class Resource{
public:
	Resource(string, int);
	
	tm getDateCreation() const{ return this->dateCreation; }
	string getName() const{ return this->name; }
	int getTypeResource();
	int isVisible() const{ return this->visible; }
	void setDateCreation(tm);
	void setName(string);
	void setVisible(int);
	~Resource();

protected:
	string name;
	tm dateCreation;
	int visible;
};

#endif