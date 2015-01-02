#ifndef URL_H
#define URL_H

#include <iostream>
using namespace std;

#include "ResourceFile.h"

class Url : public ResourceFile {
public:
	Url(string, int, string);
	int getTypeResourceFile();
	string getUrl();
	void setUrl(string);

protected:
	string url;

};

#endif
