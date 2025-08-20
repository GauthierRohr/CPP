#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// Constructeur : initialise un répertoire vide
// _count = nombre actuel de contacts
// _oldest = index du plus vieux contact (celui qu'on remplacera)
PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

bool PhoneBook::addContact()
{
    Contact c;
    if (!c.setContact()) 
        return false;

    _contacts[_oldest] = c;
    _oldest = (_oldest + 1) % 8;
    if (_count < 8)
        _count++;
    return true;
}


static void displayHeader()
{
    std::cout << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
}

// Si char* dépasse 10 caractères, on la coupe à 9 et on met un point à la fin
// static std::string truncate(std::string str)
// {
// 	return (str.length() > 10) ? str.substr(0, 9) + "." : str;
// }

// Affiche tableau de contacts enregistrés
// Demande à l'utilisateur de choisir un index à afficher
// Si index invalide, renvoie : "Invalid index"
//
// std::cin.clear() :
// 		- si entrée invalide avant, le flux est en état "d’échec" (failbit)
//		- tant que ce flag n’est pas effacé avec `.clear()`, le flux refuse de lire de nouvelles données
//
// std::cin.clear(); // ⚠ remet le flux en état OK (reset failbit)
//
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); :
// Avec std::cin >> index, on lit un nombre mais le \n (touche “Entrée”) reste dans le buffer : on le clean
// 		- signifie : « le plus de caractères possible » jusqu'à ce qu'il y ait une nouvelle ligne
//		- garantit qu’on vide TOUT le buffer
void PhoneBook::searchContact() const
{
	if (_count == 0)
	{
		std::cout << "No contacts.\n";
		return;
	}
	std::cout << "\n";
	displayHeader();

	for (int i = 0; i < _count; ++i)
	{
		_contacts[i].displayContactShort(i + 1);
	}

	std::cout << "\nEnter index: ";
	int index;
	if (!(std::cin >> index) || index < 1 || index > _count) \
	{
		std::cout << "Invalid index.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	// clean \n si index valide
	std::cin.ignore();

	// Si tout est ok
	_contacts[index - 1].displayContactFull();
}

// Permet de modifier un contact existant
// void PhoneBook::modifyContact()
// {
//     if (_count == 0)
//     {
//         std::cout << "No contacts. Please, ADD at least 1 contact.\n";
//         return;
//     }

// 	std::cout << "\nActual contact list :\n";
// 	displayHeader();
// 	for (int i = 0; i < _count; ++i)
// 	{
// 		_contacts[i].displayContactShort(i + 1);
// 	}

//     std::cout << "\nEnter the index of the contact to modify: ";
//     int index;
//     if (!(std::cin >> index) || index < 1 || index > _count)
//     {
//         std::cout << "Invalid index.\n";
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         return;
//     }

//     std::cin.ignore();
    
// 	Contact& oldContact = _contacts[index - 1];
//     std::cout << "\nOld contact info:\n";
//     oldContact.displayContactFull();

//     Contact newContact;
//     std::cout << "\nEnter new contact information:\n";
//     newContact.setContact();

//     if (!newContact.isValid())
//     {
//         std::cout << "⚠️ All fields must be filled. Modification cancelled.\n";
//         return;
//     }

//     std::cout << "\nOld summary:\n";
// 	displayHeader();
//     oldContact.displayContactShort(index);

//     std::cout << "\nNew summary:\n";
// 	displayHeader();
//     newContact.displayContactShort(index);
// 	std::cout << "\n";

//     _contacts[index - 1] = newContact;
// }