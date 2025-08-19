#include <iostream>     // pour std::cout, std::cin
#include <string>       // pour std::string
#include "PhoneBook.hpp" // pour la classe PhoneBook

int main()
{
    PhoneBook pb;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, MODIFY, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
            pb.addContact();
        else if (command == "SEARCH")
            pb.searchContact();
        else if (command == "MODIFY")
            pb.modifyContact();
        else if (command == "EXIT")
            break;
    }
    return 0;
}