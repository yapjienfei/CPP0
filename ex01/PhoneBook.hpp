#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int     _oldestIndex;
        int     _contactCount;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContact() const;
        void displayTable() const;
};

#endif