#include "Zombie.hpp"

// prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

// delete :
// Fait deux choses automatiquement :
//	1.	Appelle le destructeur de l’objet pointé par heapZombie
//	2.	Libère la mémoire allouée sur la heap (le tas) pour cet objet
//
int main(void)
{
	Zombie* heapZombie = newZombie("Heap Walker");
	heapZombie->announce();
	delete (heapZombie);

	randomChump("Stack Walker");

	return (0);
}