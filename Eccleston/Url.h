#ifndef URL_H
#define URL_H

#include <iostream>
using namespace std;

#include "Resource.h"

class Url : public Resource {
public:
	Url(string, int, string);
	int getTypeResource();
	string getUrl();
	void setUrl(string);

protected:
	string url;

};

#endif
