#include "Zombie.hpp"

// Crée un zombie sur la pile (stack), le fait annoncer puis meurt automatiquement
// Destructeur appelé automatiquement à la fin du scope
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
