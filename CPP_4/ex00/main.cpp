#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Ex00" << std::endl;

	const Animal* premierDuNom = new Animal();
	const Animal* jeSuisUnChien = new Dog();
	const Animal* jeSuisUnChat = new Cat();

	std::cout << std::endl;

	std::cout << "Type premierDuNom = " << premierDuNom->getType() << std::endl;
	std::cout << "Type jeSuisUnChien = " << jeSuisUnChien->getType() << std::endl;
	std::cout << "Type jeSuisUnChat = " << jeSuisUnChat->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "SOUNDS :" << std::endl;
	premierDuNom->makeSound();
	jeSuisUnChat->makeSound();
	jeSuisUnChien->makeSound();

	std::cout << std::endl;

	std::cout << "WRONG TEST" << std::endl;

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wc->getType() << std::endl;

	// Ca va appeler WrongAnimal::makeSound
	// car PAS virtual dans la classe de base
	wc->makeSound();

	std::cout << std::endl;

	std::cout << "THANKS FOR WATCHING" << std::endl;
	std::cout << "HIT THE LIKE AND SUBSCRIBE BUTTON" << std::endl;

	delete premierDuNom;
	delete jeSuisUnChien;
	delete jeSuisUnChat;

	delete wa;
	delete wc;

	std::cout << "END" << std::endl;

	return 0;
}

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound();
// j->makeSound();
// meta->makeSound();

// return 0;
// }
