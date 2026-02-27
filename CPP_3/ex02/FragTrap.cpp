#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left and can't attack!" << std::endl;
		return;
	}

	_energyPoints--;

	std::cout << "FragTrap " << _name
			  << " powerfully attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage! Energy left : " << _energyPoints
			  << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
			  << " wants a sensual high-five!" << std::endl;
}