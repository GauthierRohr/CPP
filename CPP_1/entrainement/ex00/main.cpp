#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie* heapzombie = newZombie("Gauthier");
	heapzombie->announce();
	delete heapzombie;

	randomChump("Anais");

	return (0);
}