#include "Fixed.hpp"

//getRawBits = “obtenir la valeur brute” ou “lire la valeur interne brute”.
// donc là en gros on veut récupérer la valeur interne de l'objet.

int main( void )

{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}