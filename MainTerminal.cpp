#include <stdlib.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include "projResource.h"
#include "ModelEccleston.h"
#include "Admin.h"
#include "ModelEccleston.h"

using namespace std;

int main(){
	ModelEccleston *mod = new ModelEccleston();
	Admin *adm = new Admin("Steven", "Klinger", "123", "PhantomD", "projet@mail.ru", mod);

	std::cout << "Bienvenue sur Eccleston\n\n" << "Veuillez rentrer votre login :\n" << endl;
	string login;
	getline(cin, login);
	std::cout << "\nVeuillez rentrer maintenant votre mot de passe\n" << endl;
	string password;
	getline(cin, password);

	std::cout << login << password << endl;

	system("PAUSE");
}
