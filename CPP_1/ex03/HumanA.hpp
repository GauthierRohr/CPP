#ifndef HUMAN_A
# define HUMAN_A

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &weapon; // reference: always armed

	public:
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();

    void attack() const;
};

#endif