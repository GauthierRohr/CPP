#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "TEST LA BASEEE" << std::endl;

	const Animal* premierDuNom = new Dog();
	const Animal* jeSuisUnChat = new Cat();

	premierDuNom->makeSound();
	jeSuisUnChat->makeSound();

	delete premierDuNom;
	delete jeSuisUnChat;

	std::cout << std::endl;
	std::cout << "ARRAY" << std::endl;

	Animal* animals[6];

	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();

	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();

	std::cout << std::endl;

	for (int k = 0; k < 6; k++)
		delete animals[k];

	std::cout << std::endl;
	std::cout << "DEEP COPY" << std::endl;

	Dog dog1;
	dog1.setIdea(0, "J'aime les os wouf");

	Dog dog2 = dog1;

	std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

	dog2.setIdea(0, "JE SUIS DIFFERENT");

	std::cout << std::endl;
	std::cout << "APRES MODIF dog2 :" << std::endl;
	std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

	std::cout << std::endl;
	// const Animal* a = new Animal(); // ERREUR COMPIL -> abstraite

	std::cout << "THX FOR WATCHING" << std::endl;
	std::cout << "HIT THE LIKE AND SUBSCRIBE BUTTON" << std::endl;

	return (0);
}
