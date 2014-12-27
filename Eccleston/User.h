#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User{
public:
	User(string, string, string, string, string);
	int checkEmail();
	string getEmail() const{ return this->email; }
	string getFirstName() const{ return this->firstName; }
	string getLogin() const{ return this->login; }
	string getName() const { return this->name; }
	string getPassword() const{ return this->password; }
	int getUserType();
	void setEmail(string);
	void setFirstName(string);
	void setLogin(string);
	void setName(string);
	void setPassword(string);
	void setUserType(string);
	~User();

protected:
	string firstName;
	string name;
	string password;
	string login;
	string email;
};

#endif
