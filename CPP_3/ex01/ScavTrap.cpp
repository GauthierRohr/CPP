#include "ScavTrap.hpp"

// C'est comme ça qu'on fait pour faire hériter de ClapTrap
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap is dead and can't attack!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap has no energy left and can't attack!" << std::endl;
		return;
	}

	energyPoints--;

	std::cout << "ScavTrap " << name
			  << " violently attacks " << target
			  << ", causing " << attackDamage
			  << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout 
	<< "ScavTrap " << name
	<< " is now in Gate keeper mode." << std::endl;
}
