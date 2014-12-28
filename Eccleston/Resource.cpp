#include "Resource.h"
#include <iostream>
#include <string>

Resource::Resource(string name, tm dateCreation, int visible){
	this->name = name;
	this->dateCreation = dateCreation;
	this->visible = visible;
}


Resource::~Resource(){

}