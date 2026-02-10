#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name):
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " created!" << std::endl;
}

// Copie tous les paramètres sans avoir à tout réassigner, PRATIQUE MON GARS
//
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
		return;
	}

	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
		return;
	}

	if (attackDamage < 0)
	{
		std::cout << "Attack damages must be at least 0" << std::endl;
		return;
	}

	energyPoints--;

	std::cout
		<< "ClapTrap " << name
		<< " attacks " << target
		<< ", causing " << attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
		return;
	}

	hitPoints -= amount;

	if (hitPoints < 0)
		hitPoints = 0;

	if (amount > 1)
	{
		std::cout << "ClapTrap " << name
				  << " takes " << amount
				  << " damages! Remaining HP: "
				  << hitPoints << std::endl;
	}
	if (amount == 0 || amount == 1)
	{
		std::cout << "ClapTrap " << name
				  << " takes " << amount
				  << " damage! Remaining HP: "
				  << hitPoints << std::endl;
	}
}

// Reparation
//
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot be repaired!"
				  << std::endl;
		return;
	}

	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to repair!"
				  << std::endl;
		return;
	}

	energyPoints--;
	hitPoints += amount;

	std::cout << "ClapTrap " << name
			  << " repairs itself for " << amount
			  << " hit points! Current HP: "
			  << hitPoints << std::endl;
}
