#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
using namespace std;

class Notification
{
public:
	Notification();
	Notification::Notification(string subject, string message, tm datereceive);
	string getSubject();
	string getMessage();
	tm getDateRecive();
	void setSubject(string);
	void setMessage(string);
	void setDateRecive(tm);
	~Notification();

protected:
	string subject;
	string message;
	struct tm dateRecive;
};


#endif