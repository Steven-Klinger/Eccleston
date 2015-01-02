#include "ResourceFile.h"
#include <iostream>
#include <string>

ResourceFile::ResourceFile(string name, int visible){
	this->name = name;
	this->dateCreation = tm();
	this->visible = visible;
}

int ResourceFile::getTypeResourceFile(){
	return 0;
}

void ResourceFile::setDateCreation(tm time){
	dateCreation = time;
}

void ResourceFile::setName(string s){
	name = s;
}

void ResourceFile::setVisible(int i){
	visible = i;
}

ResourceFile::~ResourceFile(){

}