#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
		return;
	}

	_energyPoints--;

	std::cout
		<< "ClapTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}

	// Underflow :)
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	if (amount > 1)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount
				  << " damages! Remaining HP: " << _hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount
				  << " damage! Remaining HP: " << _hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired!"
				  << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy to repair!"
				  << std::endl;
		return;
	}

	_energyPoints--;
	_hitPoints += amount;

	std::cout << "ClapTrap " << _name
			  << " repairs itself for " << amount
			  << " hit points! Current HP: "
			  << _hitPoints << std::endl;
}
