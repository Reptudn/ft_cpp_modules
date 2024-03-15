#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <array>

class Contact
{
    public:
        std::string name;
        std::string surname;
        std::string phone_number;
        long        create_timestamp;
};

class PhoneBook
{
    public:
        std::array<Contact, 8>  contacts;
        int                     count;

        PhoneBook();
        void    add();
        void    search();
};

#endif