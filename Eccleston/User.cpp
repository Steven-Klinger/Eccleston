#include<iostream>
#include "User.h"
#include <string>
#include "ModelEccleston.h"


User::User(){
	this->name = "";
	this->firstName = "";
	this->login = "";
	this->password = "";
	this->email = ""; 
	//this->mde = &(new ModelEccleston());
	this->userType = -1;
}

User::User(string name, string firstName, string login, string password, string email, ModelEccleston* model, int userType){
	
	this->name = name;
	this->firstName = firstName;
	this->login = login;
	this->password = password;
	this->email = email;
	this->mde = model;
	this->userType = userType;
}


void User::setName(string s){
	name = s;
}


void User::setFirstName(string s){
	firstName = s;
}

void User::setLogin(string s){
	login = s;
}

void User::setPassword(string s){
	password = s;
}

void User::setEmail(string s){
	email = s;
}

int User::checkEmail(){
	std::string a = "@";
	std::string b = email;
	std::string c = ".";

	std::size_t found = b.find(a);
	std::size_t fi = c.find(c);
	
	if (found != std::string::npos){
		if (fi != std::string::npos){
			return 1;
		}
	}
	else{
		return 0;
	}
}


User::~User(){

}

