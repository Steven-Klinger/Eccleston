#include <iostream>
#include <string>
using namespace std;

#include "Lesson.h"
#include "Lesson.h"
#include "User.h"

int main(void) {

	// marche po :/
	std::string prenom = "erwan";
	std::cout << prenom << '\n';
	User usvide = User();
	User us1 = User("erwan", "mellinger", "chppr", "prout", "chppr@chppr.chppr");
	
	printf("----------USER 1 --------------\n");
	std::cout << "prenom " << us1.getFirstName() << '\n';
	std::cout << "nom " << us1.getName() << '\n';
	std::cout << "login " << us1.getLogin() << '\n';
	std::cout << "mdp " << us1.getPassword() << '\n';
	std::cout << "email " << us1.getEmail() << '\n';


	system("pause");
	return 0;
}
