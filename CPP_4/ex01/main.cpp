#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== BASIC TEST ===" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "=== ARRAY TEST ===" << std::endl;

	Animal* animals[6];

	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();

	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();

	std::cout << std::endl;

	for (int k = 0; k < 6; k++)
		delete animals[k];

	std::cout << std::endl;
	std::cout << "=== DEEP COPY TEST ===" << std::endl;

	Dog dog1;
	dog1.setIdea(0, "J'aime les os");
	dog1.setIdea(1, "Je veux dormir");

	Dog dog2 = dog1;

	std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

	dog2.setIdea(0, "JE SUIS DIFFERENT");

	std::cout << std::endl;
	std::cout << "APRES MODIF dog2 :" << std::endl;
	std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "=== END ===" << std::endl;

	return 0;
}
