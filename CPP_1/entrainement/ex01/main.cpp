#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string(name));

int main(void)
{
	const int N = 5;
	std::string names[N] =
	{
		"Anaïs",
		"Gauthier",
		"Gabriel",
		"Tristan",
		"Étienne"
	};

	Zombie* horde = zombieHorde(N, "");

	for (int i = 0; i < N; i++)
	{
		horde[i].setName(names[i]);
	}

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete [] horde;
	return (0);
}