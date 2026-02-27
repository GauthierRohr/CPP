#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

// 💥 COPIE PROFONDE
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;

	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);

		delete brain;
		brain = new Brain(*other.brain);
	}

	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOUF WOUF 🐶" << std::endl;
}

void Dog::setIdea(int i, const std::string& idea)
{
	brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	return brain->getIdea(i);
}
