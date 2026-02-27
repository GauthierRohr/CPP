#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

// Sans virtual pour makeSound, le compilateur décide quelle fonction appeler en se basant
// sur le type du pointeur ->ce qu'il voit à la compilation
// et non sur le type de l'objet réel -> ce qui existe en mémoire à l'exécution.
// Genre :
// 		Animal* ptr = new Dog();
// 		ptr->makeSound();
// Avec virtual : Le programme voit que c'est un Dog caché derrière le pointeur Animal et affiche le bruit du chien.
// Sans virtual : Le programme s'arrête au type du pointeur (Animal*) et appelle Animal::makeSound()
//
// Le Destructeur
// Si le destructeur dans Animal est pas virtual,
// faire un delete sur un pointeur de la classe de base qui pointe vers une classe dérivée
// provoque un comportement indéfini -> ça leak souvent
// Genre :
// 		Animal* j = new Dog();
// 		delete j;
// Si le destructeur est virtual : Le programme appelle d'abord ~Dog() puis ~Animal() -> Clean
// Sinon : Seul ~Animal() est appelé.
// -> Donc si Dog avait alloué de la mémoire (comme Brain dans ex01) -> mémoire jamais libérée
class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;

		virtual void makeSound() const;
};

#endif