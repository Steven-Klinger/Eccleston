#include<iostream>
#include "File.h"
#include <string>
#include "Resource.h"


File::File(string name,tm dateCreation, int visible, string path) : Resource(name,dateCreation,visible){
	this->path = path;
}

string File::getPath(){

	return path;

}

void File::setPath(string path){

	this->path = path;
}
