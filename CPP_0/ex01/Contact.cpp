#include "Contact.hpp"
#include <iostream>
#include <iomanip> // pour std::setw

////////////////////////////////////////
//////////// SET CONCTACT //////////////
////////////////////////////////////////

// Vérifie si le numéro de téléphone est valide
// 		- pas vide
// 		- vérifie si le 1er caractère est '+' suivi de chiffres ou seulement chiffres
//		- Juste un '+' : pas valide
static bool isValidPhoneNumber(const std::string& number)
{
	if (number.empty())
		return false;

	size_t start = 0;
	if (number[0] == '+')
	{
		if (number.length() == 1)
			return false;
		start = 1;
	}
	for (size_t i = start; i < number.length(); i++)
	{
		if (!std::isdigit(number[i]))
			return false;
	}
	return true;
}

static bool isEmptyOrSpaces(const std::string& str)
{
	if (str.empty())
		return true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

// Retourne "EOF" si Ctrl+D est détecté
// Retourne "" si Ctrl+D est détecté
static std::string getValidInput(const std::string& prompt, bool isPhoneNumber) 
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return "";
        if (isEmptyOrSpaces(input))
        {
            std::cout << "⚠️ Input can't be empty or contain only spaces. Please try again.\n";
            continue;
        }
        if (isPhoneNumber && !isValidPhoneNumber(input))
        {
            std::cout << "⚠️ Phone number can only contain digits (and '+' at start). Please try again.\n";
            continue;
        }
        return input;
    }
}


bool Contact::setContact()
{
    std::string input;

    input = getValidInput("First name: ", false);
    if (input.empty())
		return false;
    _firstName = input;

    input = getValidInput("Last name: ", false);
    if (input.empty())
		return false;
    _lastName = input;

    input = getValidInput("Nickname: ", false);
    if (input.empty())
		return false;
    _nickname = input;

    input = getValidInput("Phone number: ", true);
    if (input.empty())
		return false;
    _phoneNumber = input;

    input = getValidInput("Darkest secret: ", false);
    if (input.empty())
		return false;
    _darkestSecret = input;

    return true;
}




//////////////////////////////////////////////////
//////////////////////////////////////////////////

static std::string truncate(const std::string& str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    else
    {
        return (str);
    }
}

// std::setw(10)
// C’est un manipulateur de flux défini dans <iomanip>
// Signifie "set width" → fixe la largeur minimale du champ d’affichage
void Contact::displayContactShort(int index) const
{
	std::cout << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::setw(10) << truncate(_firstName);
	std::cout << "|";
	std::cout << std::setw(10) << truncate(_lastName);
	std::cout << "|";
	std::cout << std::setw(10) << truncate(_nickname) << std::endl;
}

void Contact::displayContactFull() const
{
	std::cout << "First Name: " << _firstName << "\n";
	std::cout << "Last Name: " << _lastName << "\n";
	std::cout << "Nickname: " << _nickname << "\n";
	std::cout << "Phone Number: " << _phoneNumber << "\n";
	std::cout << "Darkest Secret: " << _darkestSecret << "\n";
}
