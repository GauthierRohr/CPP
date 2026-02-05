#include "Zombie.hpp"

// prototypes nécessaires
Zombie* newZombie(std::string name);
void randomChump(std::string name);

// delete :
// -> Appelle le destructeur de l’objet pointé par heapZombie
// -> Libère la mémoire allouée sur la heap (le tas) pour cet objet
//
int main(void)
{
	Zombie* heapZombie = newZombie("Heap");
	heapZombie->announce();
	

	randomChump("Stack");
	delete (heapZombie);

	return (0);
}
