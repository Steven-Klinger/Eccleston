#include<iostream>

class User
{

public:
	char* getFirstName() const{ return this->firstName; }
	char* getName() const { return this->name; }
	char* getPassword() const{ return this->password; }
	char* getLogin() const{ return this->login; }
	char* getEmail() const{ return this->email; }

protected :
	char* firstName;
	char* name;
	char* password;
	char* login;
	char* email;
};
