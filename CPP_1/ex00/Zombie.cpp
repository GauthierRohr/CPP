// TO DO LIST

// Quand un zombie apparait, je dois ecrire :
// <name>: BraiiiiiiinnnzzzZ...
// Grostier: BraiiiiiiinnnzzzZ...
//
// Now, what is the actual point of the exercise? You have to determine in which case
// It is better to allocate zombies on the stack or the heap.
//
// Zombies must be destroyed when you no longer need them.
// The destructor must print a message with the name of the zombie for debugging purposes.

#include "Zombie.hpp"
#include <iostream>

// "Zombie::Zombie(std::string name)" 	: constructeur
// ": _name(name)" 						: C’est la liste d’initialisation
//											-> « Initialise _name avec la valeur passée en argument (name) »
// En gros, c'est comme faire :
//	Zombie::Zombie(std::string name) {
//    _name = name;
//	}
//
// “Quand quelqu’un crée un zombie en passant un nom, je stocke ce nom dans l’attribut privé _name de l’objet.”
// _name est unique à chaque zombie, car il est stocké dans l’objet lui-même.
//
Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
