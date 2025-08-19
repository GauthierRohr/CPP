#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    void setContact();
    void displayContactShort(int index) const;
    void displayContactFull() const;
    bool isValid() const;
};

#endif