#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << std::endl;
    std::cout << "======== CONSTRUCTEURS ========" << std::endl;
	std::cout << std::endl;

    Fixed a;                    // default
    Fixed b(10);                // from int
    Fixed c(42.42f);            // from float
    Fixed d(b);                 // copy

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

	std::cout << std::endl;
    std::cout << "======== ARITHMÉTIQUE ========" << std::endl;
	std::cout << std::endl;

    Fixed x(5.5f);
    Fixed y(2);

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << std::endl;
    std::cout << "======== COMPARAISONS ========" << std::endl;
	std::cout << std::endl;

    std::cout << (x > y)  << " : x > y"  << std::endl;
    std::cout << (x < y)  << " : x < y"  << std::endl;
    std::cout << (x >= y) << " : x >= y" << std::endl;
    std::cout << (x <= y) << " : x <= y" << std::endl;
    std::cout << (x == y) << " : x == y" << std::endl;
    std::cout << (x != y) << " : x != y" << std::endl;

	std::cout << std::endl;
    std::cout << "======== INCRÉMENTATION / DÉCRÉMENTATION ========" << std::endl;
	std::cout << std::endl;

    Fixed inc;

    std::cout << "inc     = " << inc << std::endl;
    std::cout << "++inc   = " << ++inc << std::endl;   // pre
    std::cout << "inc     = " << inc << std::endl;

    std::cout << "inc++   = " << inc++ << std::endl;   // post
    std::cout << "inc     = " << inc << std::endl;

    std::cout << "--inc   = " << --inc << std::endl;
    std::cout << "inc--   = " << inc-- << std::endl;
    std::cout << "inc     = " << inc << std::endl;

	std::cout << std::endl;
    std::cout << "======== MIN / MAX ========" << std::endl;
	std::cout << std::endl;

    Fixed m1(3.3f);
    Fixed m2(7.7f);

    std::cout << "m1 = " << m1 << std::endl;
    std::cout << "m2 = " << m2 << std::endl;

    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	std::cout << std::endl;
    std::cout << "======== 42 TEST ========" << std::endl;
	std::cout << std::endl;

    Fixed s1;
    Fixed const s2(Fixed(5.05f) * Fixed(2));

	std::cout << std::endl;
    std::cout << s1 << std::endl;
    std::cout << ++s1 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s1++ << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << Fixed::max(s1, s2) << std::endl;

    return 0;
}