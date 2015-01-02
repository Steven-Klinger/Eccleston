#include<iostream>
#include "File.h"
#include <string>
#include "Work.h"
#include "Student.h"
#include "File.h"

Work::Work(string name, int visible, string path) : File(name, visible, path){

	this->mark = -1; //valeur par défaut
}

int Work::getMark(){

	return mark;

}

Student Work::getStudent(){

	return student;
}

int Work::getTypeResourceFile(){

	return 4;

}

void Work::setMark(int mark){
	
	this->mark = mark;
}

