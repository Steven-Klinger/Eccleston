#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "ResourceFile.h"

using namespace std;

class File : public ResourceFile
{
public:
	File(string, int, string);
	string getPath();
	void setPath(string);

protected:
	string path;
};

#endif
