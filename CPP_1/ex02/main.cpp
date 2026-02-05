// #include <string>
// #include <iostream>

// int main(void)
// {
// 	std::string s = "HI THIS IS BRAIN";
// 	std::string *stringPTR = &s;
// 	std::string &stringREF = s;

// 	// addresses
// 	std::cout << &s << std::endl;            // adresse de la string
// 	std::cout << stringPTR << std::endl;     // adresse stockée dans ptr
// 	std::cout << &stringREF << std::endl;    // adresse de la référence (= adresse de s)

// 	std::cout << std::endl;

// 	// valeurs
// 	std::cout << s << std::endl;             // valeur de la string
// 	std::cout << *stringPTR << std::endl;    // valeur pointée par le ptr
// 	std::cout << stringREF << std::endl;     // valeur en passant par la référence
// }
#include <string>
#include <iostream>

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << &s << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << s << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
