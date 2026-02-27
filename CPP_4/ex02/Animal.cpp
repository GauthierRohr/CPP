#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

// Vaut mieux mettre type(other.type) en haut que dans la boucle (*this = other)
// Ca evite des pb avec par exemple si on avait :
//		class Animal
//		 {
//		     const std::string type; // const !!!!
//		 };
//
// IMPOSSIBLE -> peut pas assigner un const après initialisation
//			Animal::Animal(const Animal& other)
//			{
//		 	*this = other; // ERREUR DE COMPILATION
// 			}
//
Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;

	if (this != &other)
		this->type = other.type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

// Faut juste delete ca pour donner du pur virtuel :
// void Animal::makeSound() const
// {
// 	std::cout << "Animal generic sound : miawouf" << std::endl;
// }
