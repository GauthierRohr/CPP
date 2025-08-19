#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name); // Prototype de la fonction

int main()
{
    const int N = 5;
    std::string names[N] =
	{
		"Tom",
		"Gauthier",
		"Anais",
		"Karl",
		"Côme"
	};

    Zombie* horde = zombieHorde(N, "");

    for (int i = 0; i < N; ++i)
        horde[i].setName(names[i]);

    for (int i = 0; i < N; ++i)
        horde[i].announce();

    delete[] horde;
    return 0;
}
