#include "Zombie.hpp"

// Crée un zombie sur la heap (tas) -> utilisable en dehors de la scope
Zombie* newZombie( std::string name )
{
	return new Zombie(name);
}
