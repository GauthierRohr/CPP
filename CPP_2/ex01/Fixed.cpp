#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

// 256 = 2^8;
// Je peux juste faire n * 256 c'est pareil.
// On utilise << dans la plupart des implémentations
//		Un peu plus rapide pour le CPU → instruction binaire simple
// 		Plus clair pour un habitué au fixed point : le décalage = “place la valeur entière dans les bits de poids fort”
// 		Porté à tous les nombres sans réfléchir au 2ⁿ : si tu changes _fractionalBits en 10 → 1 << 10
//
Fixed::Fixed(const int n)
{
	_fixedPointValue = n << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

// << ne fonctionne pas sur des floats → marche que sur des entiers
// Donc on utilise 1 << fractionalBits = 1 * 2^8 = 256.
// _fixedPointValue est un entier (int), donc on est obligé d'arrondir le stockage, sans virgule.
//
// 	Ex :
// 	f = 0.1
//	0.1 × 256 = 25.6
//
//	D'où roundf :
//	roundf(25.6) → 26
//
Fixed::Fixed(const float f)
{
	_fixedPointValue = roundf(f * (1 <<_fractionalBits));
	std::cout << "Float construtor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
	{
		_fixedPointValue = copy.getRawBits();
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// . ne marche pas car this = un pointeur vers obj courant
// obligé d'utiliser -> pour les ptr.
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return ( (float) _fixedPointValue / 256 );
}

int		Fixed::toInt( void ) const
{
	return ( (int) _fixedPointValue >> _fractionalBits );
}

// C++ ne sait pas automatiquement comment afficher l' objet Fixed
// 		-> Il n’y a pas de “mode natif” pour les objets créés
//		-> Résultat sans surcharge d'opérateur : erreur de compilation
//
// convertit Fixed → float et l’envoie dans le flux
std::ostream& operator<<(std::ostream& outputStream, const Fixed& f)
{
    outputStream << f.toFloat();
    return (outputStream);
}
