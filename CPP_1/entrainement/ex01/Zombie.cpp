#include "Zombie.hpp"

Zombie::Zombie() : _name("") {}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " has been shot" << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}