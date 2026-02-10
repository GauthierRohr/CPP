#include "ClapTrap.hpp"

int main()
{
	std::cout << "CREATION :" << std::endl;
	ClapTrap a("Grosthier");
	ClapTrap b("HumanShield");
	std::cout << std::endl;

	std::cout << "ATTACK :" << std::endl;
	a.attack("HumanShield");
	b.takeDamage(3);
	std::cout << std::endl;

	std::cout << "REPAIR" << std::endl;
	b.beRepaired(5);
	std::cout << std::endl;

	std::cout << "ENERGY" << std::endl;
	for (int i = 0; i < 11; i++)
		a.attack("UndeservedVictim");
	std::cout << std::endl;

	std::cout << "DAMAGE TIL DEATH" << std::endl;
	b.takeDamage(20);
	b.attack("Grosthier");
	b.beRepaired(10);
	std::cout << std::endl;

	std::cout << "COPY" << std::endl;
	ClapTrap c("ThisNameWillBeReplacedAfterAssignation");
	c = a;
	c.attack("RandomCopy");
	std::cout << std::endl;

	std::cout << "THX FOR WATCHING" << std::endl;
	return (0);
}
