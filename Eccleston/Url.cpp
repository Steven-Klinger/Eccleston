#include<iostream>
#include "Url.h"
#include <string>

Url::Url(string name, int visible, string url) : ResourceFile(name, visible){
	this->url = url;
}

int Url::getTypeResourceFile(){

	return 0;

}

string Url::getUrl(){

	return url;

}

void Url::setUrl(string s){

	this->url = s;

}
