#ifndef FILE_H
#define FILE_H
#include <iostream>

using namespace std;

class File{
public:
	File(string, int, string);
	string getPath();
	void setPath(string);

protected:
	string path;
};

#endif
