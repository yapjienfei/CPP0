#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : _oldestIndex(0), _contactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

static std::string sanitize(const std::string &str)
{
    std::string result;
    result.reserve(str.length());
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it == '\t')
            result.push_back(' ');
        else
            result.push_back(*it);
    }
    return result;
}

static std::string truncate(const std::string &str)
{
    if (str.length() <= 10)
        return str;
    return str.substr(0, 9) + ".";
}

static bool safeGetline(const std::string &prompt, std::string &input)
{
    std::cout << prompt;
    if (!std::getline(std::cin, input))
        return false;
    return true;
}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    if (!safeGetline("Enter first name: ", firstName) ||
        !safeGetline("Enter last name: ", lastName) ||
        !safeGetline("Enter nickname: ", nickname) ||
        !safeGetline("Enter phone number: ", phoneNumber) ||
        !safeGetline("Enter darkest secret: ", darkestSecret))
        return;
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "All fields must be filled. Contact not added." << std::endl;
        return;
    }
    _contacts[_oldestIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    //replace the oldest contact with the new one if more than MAX_CONTACTS
    _oldestIndex = (_oldestIndex + 1) % MAX_CONTACTS;
    if (_contactCount < MAX_CONTACTS)
        _contactCount++;
    std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::displayTable() const
{
    std::cout   << "|" << std::setw(10) << "Index"
                << "|" << std::setw(10) << "First Name"
                << "|" << std::setw(10) << "Last Name"
                << "|" << std::setw(10) << "Nickname"
                << "|" << std::endl;
    for (int i = 0; i < _contactCount; ++i)
    {
        std::string firstName = sanitize(_contacts[i].getFirstName());
        std::string lastName  = sanitize(_contacts[i].getLastName());
        std::string nickname  = sanitize(_contacts[i].getNickname());
        std::cout << "|" << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(firstName) << "|"
                  << std::setw(10) << truncate(lastName) << "|"
                  << std::setw(10) << truncate(nickname) << "|"
                  << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (_contactCount == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    displayTable();
    std::string line;
    int idx;
    std::cout << "Enter index to display: ";
    if (!std::getline(std::cin, line))
        return;
    std::stringstream ss(line);
    if (!(ss >> idx) || !(ss.eof()))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    if (idx < 1 || idx > _contactCount)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    const Contact& c = _contacts[idx - 1];
    std::cout << std::left << std::setw(15) << "First name" << " :" << sanitize(c.getFirstName()) << std::endl;
    std::cout << std::left << std::setw(15) << "Last name" << " :" << sanitize(c.getLastName()) << std::endl;
    std::cout << std::left << std::setw(15) << "Nickname" << " :" << sanitize(c.getNickname()) << std::endl;
    std::cout << std::left << std::setw(15) << "Phone number" << " :" << sanitize(c.getPhoneNumber()) << std::endl;
    std::cout << std::left << std::setw(15) << "Darkest secret" << " :" << sanitize(c.getDarkestSecret()) << std::endl;
}