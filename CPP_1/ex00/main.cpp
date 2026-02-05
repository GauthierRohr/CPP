#include "Zombie.hpp"

// prototypes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

// delete :
<<<<<<< HEAD
// -> Appelle le destructeur de l’objet pointé par heapZombie
// -> Libère la mémoire allouée sur la heap (le tas) pour cet objet
//
int main(void)
{
	Zombie* heapZombie = newZombie("Heap");
=======
// Fait deux choses automatiquement :
//	1.	Appelle le destructeur de l’objet pointé par heapZombie
//	2.	Libère la mémoire allouée sur la heap (le tas) pour cet objet
//
int main(void)
{
	Zombie* heapZombie = newZombie("Heap Walker");
>>>>>>> 32a52625cc3be4f5a1fdf8785aba4dbb6529e846
	heapZombie->announce();
	

	randomChump("Stack");
	delete (heapZombie);

<<<<<<< HEAD
=======
	randomChump("Stack Walker");

>>>>>>> 32a52625cc3be4f5a1fdf8785aba4dbb6529e846
	return (0);
}
