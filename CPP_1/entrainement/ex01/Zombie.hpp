#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie (std::string _name);
		~Zombie();

		void announce(void);
		void setName(std::string name);
};

#endif