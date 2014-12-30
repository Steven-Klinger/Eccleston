#include<iostream>
#include "Url.h"
#include <string>

Url::Url(string name, int visible, string link) : Resource(string name, tm dateCreation, int visible){
	this->url = url;
	this->link = link; //on l'appelle link le lien non?
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
