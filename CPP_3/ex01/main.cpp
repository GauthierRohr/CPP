#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	// EX01
	std::cout << "EX01" << std::endl;
	std::cout << "SCAVTRAP CREATION :" << std::endl;
	ScavTrap s("Guardian");
	std::cout << std::endl;

	std::cout << "SCAVTRAP ATTACK :" << std::endl;
	s.attack("Intruder");
	std::cout << std::endl;

	std::cout << "SCAVTRAP SPECIAL MODE :" << std::endl;
	s.guardGate();
	std::cout << std::endl;

	std::cout << "SCAVTRAP ENERGY TEST :" << std::endl;
	for (int i = 0; i < 52; i++)
		s.attack("PoorGuy");
	std::cout << std::endl;

	std::cout << "SCAVTRAP COPY :" << std::endl;
	ScavTrap s2 = s;
	s2.guardGate();
	std::cout << std::endl;

	std::cout << "THX FOR WATCHING" << std::endl;
	return (0);
}
