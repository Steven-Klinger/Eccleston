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

	mod->addUser(*adm);

	std::cout << "Bienvenue sur Eccleston\n\n" << "Veuillez rentrer votre login :\n" << endl;
	string login;
	getline(cin, login);
	std::cout << "\nVeuillez rentrer maintenant votre mot de passe\n" << endl;
	string password;
	getline(cin, password);

	if (mod->checkLogin(login, password)){
		
		std::cout << "Connexion etablie !\n" << "Liste des fonctions disponibles :\n\n" << "1. Ajouter un Utilisateur\n" << "2. Supprimer un Utilisateur\n\n" << endl ;

	}
	else
	{
		std::cout << "Connexion impossible !\n" << endl;
	}



	system("PAUSE");
}
