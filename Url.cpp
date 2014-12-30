#include<iostream>
#include "Url.h"
#include <string>

Url::Url(string name, int visible, string path) : File(string name, int visible, string path){
	this->url = url;
}

int Url::getTypeResource(){

	return 0;

}

string Url::getUrl(){

	return url;

}

void Url::setUrl(string s){

	this->url = s;

}
