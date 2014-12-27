#include<iostream>
#include "User.h"
#include <string>


User::User(string name, string firstName, string login, string password, string email){

	this->name = name;
	this->firstName = firstName;
	this->login = login;
	this->password = password;
	this->email = email;
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
	return 0;
}

int User::getUserType(){
	return 0;
}

User::~User(){

}
