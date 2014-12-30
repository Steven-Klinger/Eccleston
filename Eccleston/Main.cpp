#include <iostream>
#include <string>
using namespace std;

#include "Lesson.h"
#include "Student.h"
#include "User.h"
#include "ModelEccleston.h"

int main(void) {

	// marche po :/
	std::string prenom = "erwan";
	std::cout << prenom << '\n';
	User usvide = User();
	User us1 = User("mellinger", "erwan", "chppr", "prout", "chppr@chppr.chppr");
	User us2 = User("Merkling", "Raphael", "Desmero", "prout", "chppr@chppr.chppr");
	User us3 = User("Anduze", "Nicolas", "NICO", "prout", "chppr@chppr.chppr");
	User us4 = User("Klinger", "Steven", "PhantomD", "prout", "chppr@chppr.chppr");

	printf("\n----------USER1 --------------\n");
	std::cout << "prenom " << us1.getFirstName() << '\n';
	std::cout << "nom " << us1.getName() << '\n';
	std::cout << "login " << us1.getLogin() << '\n';
	std::cout << "mdp " << us1.getPassword() << '\n';
	std::cout << "email " << us1.getEmail() << '\n';

	printf("\n---------- TEST MODELE --------------\n");
	ModelEccleston me;
	me.addUser(us1);
	me.addUser(us2);
	me.addUser(us3);
	me.addUser(us4);
	for (int i = 0; i < 4; i++){
		std::cout << "prenom du user "<< i << " : "<< me.getUser(i).getFirstName() << '\n';
	}

	printf("\n----------SUPP USR --------------\n");
	me.removeUser(us1);
	for (int i = 0; i < 3; i++){
		std::cout << "prenom du user " << i << " : " << me.getUser(i).getFirstName() << '\n';
	}

	printf("\n---------- RAJOUT USR 1 --------------\n");
	me.addUser(us1);
	for (int i = 0; i < 4; i++){
		std::cout << "prenom du user " << i << " : " << me.getUser(i).getFirstName() << '\n';
	}

	printf("\n---------- GET USERBY LOGIN CHPPR --------------\n");
	std::cout << "on cherche le prenom de chppr :" << me.getUserByLogin("chppr").getFirstName() << '\n';

	printf("\n---------- is chppr@chppr.chppr available ? --------------\n");
	std::cout << "" << me.checkEMailAvailable("chppr@chppr.chppr") << '\n';
	
	printf("\n---------- CREAT STUDENT --------------\n");
	Student st1 = Student("Mellinger","Erwan le student","erwan","proot","azeza");
	me.addUser(st1);
	for (int i = 0; i < 5; i++){
		std::cout << "prenom du user " << i << " : " << me.getUser(i).getFirstName() << '\n';
	}

	system("pause");
	return 0;
}
