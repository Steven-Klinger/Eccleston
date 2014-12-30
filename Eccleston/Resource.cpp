#include "Resource.h"
#include <iostream>
#include <string>

Resource::Resource(string name, int visible){
	this->name = name;
	this->dateCreation = tm();
	this->visible = visible;
}

int Resource::getTypeResource(){
	return 0;
}

void Resource::setDateCreation(tm time){
	dateCreation = time;
}

void Resource::setName(string s){
	name = s;
}

void Resource::setVisible(int i){
	visible = i;
}

Resource::~Resource(){

}