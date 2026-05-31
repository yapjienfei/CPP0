#include "Contact.hpp"

Contact::Contact()
{ 
}

Contact::~Contact()
{
}

void Contact::setContact(const std::string& first, const std::string& last,
                         const std::string& nick, const std::string& phone,
                         const std::string& secret)
{
    _firstName = first;
    _lastName = last;
    _nickname = nick;
    _phoneNumber = phone;
    _darkestSecret = secret;
}

std::string Contact::getFirstName() const
{ 
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const 
{ 
    return _nickname; 
}

std::string Contact::getPhoneNumber() const 
{ 
    return _phoneNumber; 
}

std::string Contact::getDarkestSecret() const
{ 
    return _darkestSecret;
}
