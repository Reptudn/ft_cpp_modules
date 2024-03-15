#include <iostream>
#include <string>

void    add()
{
    std::cout << "ADD" << std::endl;
}

void    search()
{
    std::cout << "SEARCH" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 1)
        return 1;

    while(true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (input == "ADD")
            add();
        else if (input == "SEARCH")
            search();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Invalid command: " + input << std::endl;
    }
    return 0;
}