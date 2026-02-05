#include <iostream>     // pour std::cout, std::cin
#include <string>       // pour std::string
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break;
        }
        if (command == "ADD")
        {
            if (!pb.addContact())
                break;
        }
        else if (command == "SEARCH")
            pb.searchContact();
        else if (command == "EXIT")
            break;
    }
    return 0;
}
