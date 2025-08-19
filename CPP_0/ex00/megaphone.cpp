// Prendre des argv
// Les afficher :
//	- en MAJUSCULES
//	- sur une seule ligne
//	- collés à la suite
//
// Si aucun argument, afficher :
//	- "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
//

#include <iostream> // pour std
#include <cctype>   // pour std::toupper (apparemment grace au compilateur, peut fonctionner sans)

void ft_print_args(char **args)
{
	int i = 1;
	while (args[i])
	{
		int j = 0;
		while (args[i][j])
		{
			std::cout << (char)std::toupper(args[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl; //saut de ligne
}

int	main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
		ft_print_args(av);
	return (0);
}
