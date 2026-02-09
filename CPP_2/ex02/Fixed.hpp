#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed& copy);

		// Ops de comparaison
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Ops arithmetiques
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Incrementation/decrementation
		Fixed &operator++();       // Pre-increment
		Fixed operator++(int);     // Post-increment
		Fixed &operator--();       // Pre-decrement
		Fixed operator--(int);     // Post-decrement

		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

		// min / max
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif