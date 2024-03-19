#include <iostream>
#include <string>
#include "Phonebook.hpp"

int main(int argc, char **argv)
{
    if (argc != 1)
        return 1;

    std::cout << "Welcome to the phonebook!" << std::endl;

    PhoneBook book;

    while(true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (input == "ADD")
            book.add();
        else if (input == "SEARCH")
            book.search();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Invalid command: " + input << std::endl;
    }
    return 0;
}