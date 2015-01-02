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

	if (mod->checkLogin(login, password) && (adm->checkEmail() == 1)){

		std::cout << "Connexion etablie !\n\n" << "Liste des fonctions disponibles :\n\n" << endl;

		if (adm->getUserType() == 0){ //ADMIN

			std::cout << "1. Ajouter un Utilisateur\n" << "2. Supprimer un Utilisateur\n" << "3. Consulter les notifications\n" << "4. Se deconnecter\n\n" << endl;
		}

		else if (adm->getUserType() == 2) { //STUDENT

			std::cout << "1. Visualiser Cours" << "2. Consulter les notifications\n" << "3. S'inscrire a un cours\n" << "4. Se desinscrire d'un cours\n" << "5. Se deconnecter\n\n" << endl;

		}
		
		else{ //TEACHER

			std::cout << "1. Visualiser Liste de cours" << "2. Proposer cours\n" << "3. Modifier cours\n" << "4. Se deconnecet\n\n" << endl;

		}

	}
	else
	{
		std::cout << "Connexion impossible !\n" << endl;
	}

	system("PAUSE");
}
