#include <array>
#include <vector>

#include "PhoneBook.hpp"

class PhoneBook
{
    public:
        std::array<Contact, 8> contacts;
        int count;

        PhoneBook() : count(0) {
            for (Contact c : contacts)
                c.create_timestamp = 0;
        }

        void add()
        {

        }

        void search(std::string keyword)
        {
            std::cout << "SEARCH for " + keyword << std::endl;
            for (Contact c : contacts)
            {
                // not mine so rewrite this
                if (c.name.find(keyword) != std::string::npos ||
                    c.surname.find(keyword) != std::string::npos ||
                    c.phone_number.find(keyword) != std::string::npos)
                {
                    std::cout << c.name << " " << c.surname << " " << c.phone_number << std::endl;
                }
            }
            std::cout << std::endl;
        }

        ~PhoneBook()
        {
            for (Contact contact : contacts)
            {
                delete contact;
            }
        }
};