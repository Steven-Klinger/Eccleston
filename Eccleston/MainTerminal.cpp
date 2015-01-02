#include <stdlib.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include "projResource.h"
#include "ModelEccleston.h"
#include "Admin.h"
#include "ModelEccleston.h"
#include "Teacher.h"
#include "Student.h"

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

		std::cout << "Connexion etablie !\n\n" << "Liste des fonctions disponibles :\n" << endl;

		if (adm->getUserType() == 0){ //ADMIN

			std::cout << "1. Ajouter un Utilisateur\n" << "2. Supprimer un Utilisateur\n" << "3. Consulter les notifications\n" << "4. Se deconnecter\n" << "Tapez le chiffre correspondant à la fonction\n" << endl;
			int selection;
			cin >> selection;

			if (selection == 1) {

				std::cout << "Vous désirez ajouter un utilisateur.\n" << "Veuillez indiquer son statut :\n" << "0 pour Admin\n" << "1 pour Enseignant\n" << "2 pour Etudiant\n" << endl;
				int status;
				cin >> status;

				if (status == 0){ //ADMIN

					std::cout << "Veuillez indiquer, nom, prenom, login, mot de passe et email, appuyez sur entrée entre chacun de ces éléments\n" << endl;
					string name;
					string firstname;
					string login;
					string password;
					string email;

					cin >> name;
					cin >> firstname;
					cin >> login;
					cin >> password;
					cin >> email;

					Admin *admi = new Admin(name, firstname, login, password, email, mod);

					if (mod->checkLoginAvailable(login)) //VERIFICATIONS
					{

						if (mod->checkEMailAvailable(email)){

							if (admi->checkEmail()){

								std::cout << "Utilisateur ajoute : \n" << name << "\n" << firstname << "\n" << login << "\n" << password << "\n" << email << "\n" << endl;

							}
							else{

								std::cout << "L'email est incorrect, il manque un @ !!\n" << endl;

							}
						}
						
						else{

							std::cout << "L'email est deja pris!!\n" << endl;

						}
						
					}
					else{

						std::cout << "Le login est deja pris!!\n" << endl;
					}

				}

				else if (status == 1){

					std::cout << "Veuillez indiquer, nom, prenom, login, mot de passe et email, appuyez sur entrée entre chacun de ces éléments\n" << endl;
					string name;
					string firstname;
					string login;
					string password;
					string email;

					cin >> name;
					cin >> firstname;
					cin >> login;
					cin >> password;
					cin >> email;

					Teacher *tea = new Teacher(name, firstname, login, password, email, mod);

					if (mod->checkLoginAvailable(login)) //VERIFICATIONS
					{

						if (mod->checkEMailAvailable(email)){

							if (tea->checkEmail()){

								std::cout << "Utilisateur ajoute : \n" << name << "\n" << firstname << "\n" << login << "\n" << password << "\n" << email << "\n" << endl;

							}
							else{

								std::cout << "L'email est incorrect, il manque un @ !!\n" << endl;

							}
						}

						else{

							std::cout << "L'email est deja pris!!\n" << endl;

						}

					}
					else{

						std::cout << "Le login est deja pris!!\n" << endl;
					}

				}
				else if (status == 2){

					std::cout << "Veuillez indiquer, nom, prenom, login, mot de passe et email, appuyez sur entrée entre chacun de ces éléments\n" << endl;
					string name;
					string firstname;
					string login;
					string password;
					string email;

					cin >> name;
					cin >> firstname;
					cin >> login;
					cin >> password;
					cin >> email;

					Student *stu = new Student(name, firstname, login, password, email, mod);

					if (mod->checkLoginAvailable(login)) //VERIFICATIONS
					{

						if (mod->checkEMailAvailable(email)){

							if (stu->checkEmail()){

								std::cout << "Utilisateur ajoute : \n" << name << "\n" << firstname << "\n" << login << "\n" << password << "\n" << email << "\n" << endl;

							}
							else{

								std::cout << "L'email est incorrect, il manque un @ !!\n" << endl;

							}
						}

						else{

							std::cout << "L'email est deja pris!!\n" << endl;

						}

					}
					else{

						std::cout << "Le login est deja pris!!\n" << endl;
					}

				}
				else {

					std::cout << "Statut innexistant \n" << endl;

				}

			}
		}

		else if (adm->getUserType() == 2) { //STUDENT

			std::cout << "1. Visualiser Cours" << "2. Consulter les notifications\n" << "3. S'inscrire a un cours\n" << "4. Se desinscrire d'un cours\n" << "5. Se deconnecter\n" << endl;

		}
		
		else{ //TEACHER

			std::cout << "1. Visualiser Liste de cours" << "2. Proposer cours\n" << "3. Modifier cours\n" << "4. Se deconnecter\n" << endl;

		}

	}
	else
	{
		std::cout << "Connexion impossible !\n" << endl;
	}

	system("PAUSE");
}
