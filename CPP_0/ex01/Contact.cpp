#include "Contact.hpp"
#include <iostream>
#include <iomanip> // pour std::setw
// #include <iomanip>
// #include <cctype>
// #include <algorithm>

static bool isEmptyOrSpaces(const std::string& str) {
    return str.empty() || std::all_of(str.begin(), str.end(), isspace);
}

// Vérifie si le numéro de téléphone est valide
static bool isValidPhoneNumber(const std::string& number) {
    if (number.empty()) return false;
    
    // Vérifie si le premier caractère est '+' suivi de chiffres ou seulement chiffres
    size_t start = (number[0] == '+') ? 1 : 0;
    if (start == 1 && number.length() == 1) return false; // Juste un '+' n'est pas valide
    
    for (size_t i = start; i < number.length(); ++i) {
        if (!std::isdigit(number[i])) {
            return false;
        }
    }
    return true;
}

// Demande une entrée valide avec message personnalisé
static std::string getValidInput(const std::string& prompt, bool isPhoneNumber = false) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (isEmptyOrSpaces(input)) {
            std::cout << "⚠️ Input cannot be empty or contain only spaces. Please try again.\n";
            continue;
        }
        
        if (isPhoneNumber && !isValidPhoneNumber(input)) {
            std::cout << "⚠️ Phone number can only contain digits (and optional '+' at start). Please try again.\n";
            continue;
        }
        
        return input;
    }
}

void Contact::setContact()
{
    _firstName = getValidInput("First name: ");
    _lastName = getValidInput("Last name: ");
    _nickname = getValidInput("Nickname: ");
    _phoneNumber = getValidInput("Phone number: ", true);
    _darkestSecret = getValidInput("Darkest secret: ");
}

bool Contact::isValid() const
{
    return true;
}

static std::string truncate(const std::string& str)
{
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

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
