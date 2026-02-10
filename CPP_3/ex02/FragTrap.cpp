#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;

    std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
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
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "FragTrap is dead and can't attack!" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "FragTrap has no energy left and can't attack!" << std::endl;
        return;
    }

    energyPoints--;

    std::cout << "FragTrap " << name
              << " powerfully attacks " << target
              << ", causing " << attackDamage
              << " points of damage! Energy left : " << energyPoints
			  << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name
              << " wants a sensual high-five!" << std::endl;
}
