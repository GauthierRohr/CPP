#include "Zombie.hpp"

// prototypes nécessaires
Zombie* newZombie(std::string name);
void randomChump(std::string name);

// delete :
// Fait deux choses automatiquement :
//	1.	Appelle le destructeur de l’objet pointé par heapZombie
//	2.	Libère la mémoire allouée sur la heap (le tas) pour cet objet
//
//
int main(void)
{
	Zombie* heapZombie = newZombie("HeapZ");
	heapZombie->announce();
	delete (heapZombie);

	randomChump("StackZ");

	return (0);
}