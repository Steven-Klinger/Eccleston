#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "Resource.h"

using namespace std;

class File : public Resource
{
public:
	File(string,tm, int, string);
	string getPath();
	void setPath(string);

protected:
	string path;
};

#endif
