#include<iostream>
#include "File.h"
#include <string>

File::File(string name, int visible, string path) : Resource(string name, tm dateCreation, int visible){
	this->path = path;
}

string File::getPath(){

	return path;

}

void File::setPath(string path){

	this->path = path;
}
