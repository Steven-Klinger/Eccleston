#include<iostream>
#include "File.h"
#include <string>
#include "Work.h"
#include "Student.h"
#include "File.h"

Work::Work(string name,tm dateCreation, int visible, string path) : File(name,dateCreation,visible,path){

	this->mark = -1; //valeur par défaut
}

int Work::getMark(){

	return mark;

}

Student Work::getStudent(){

	return student;
}

int Work::getTypeResource(){

	return 4;

}

void Work::setMark(int mark){
	
	this->mark = mark;
}

