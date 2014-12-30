#ifndef URL_H
#define URL_H

#include <iostream>
using namespace std;

class Url{
public:
	Url(string, int, string);
	int getTypeResource();
	string getUrl();
	void setUrl(string);

protected:
	string url;

};

#endif
