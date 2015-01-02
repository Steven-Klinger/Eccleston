#include "Notification.h"
#include <iostream>
#include <ctime>
#include <string>

Notification::Notification()
{
}

string Notification::getSubject()
{
	return this->subject;
}

string Notification::getMessage()
{
	return this->message;
}

tm Notification::getDateRecive(){
	return this->dateRecive;
}

void Notification::setSubject(string newSub)
{
	this->subject = newSub;
}

void Notification::setMessage(string newMess)
{
	this->message = newMess;
}

void Notification::setDateRecive(tm newDR)
{
	this->dateRecive = newDR;
}

Notification::~Notification()
{
}
