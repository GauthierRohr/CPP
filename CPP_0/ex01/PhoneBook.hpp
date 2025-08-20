#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int _count;
    int _oldest;

public:
    PhoneBook();
    bool addContact();
    void searchContact() const;
    //void modifyContact();
};

#endif