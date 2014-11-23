#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class User{
public:
	User();

	char* getFirstName() const{ return this->firstName; }
	char* getName() const { return this->name; }
	char* getPassword() const{ return this->password; }
	char* getLogin() const{ return this->login; }
	char* getEmail() const{ return this->email; }

	~User();

protected:
	char* firstName;
	char* name;
	char* password;
	char* login;
	char* email;
};

#endif