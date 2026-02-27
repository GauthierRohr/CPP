#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

// virtual void makeSound() const = 0; 
// -> Virtual pur, abstract
// Ça sert à forcer les classes dérivées à implémenter makeSound()
// Evite les conneries comme oublier de faire un makesound dans les "enfants"
// Evite d'appeler direct "Animal" puisque ca a pas de sens
//
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

		virtual void makeSound() const = 0;
};

#endif