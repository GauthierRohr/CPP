#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== POLYMORPHISM TEST ===" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << "Type j = " << j->getType() << std::endl;
	std::cout << "Type i = " << i->getType() << std::endl;

	std::cout << std::endl;

	std::cout << "SOUNDS :" << std::endl;
	i->makeSound(); // doit faire MIAOU
	j->makeSound(); // doit faire WOUF
	meta->makeSound();

	std::cout << std::endl;

	std::cout << "=== WRONG TEST ===" << std::endl;

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wc->getType() << std::endl;

	// ICI → ça va appeler WrongAnimal::makeSound
	// car PAS virtual dans la classe de base
	wc->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	delete wa;
	delete wc;

	std::cout << "=== END ===" << std::endl;

	return 0;
}
