/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:50:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 09:50:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

#define CLEAR "\033c"

void PrintCommans()
{
    std::cout << "Available commands:" << std::endl;
    std::cout << "ADD (add a contact)" << std::endl;
    std::cout << "SEARCH (using a keyword search for contacts)" << std::endl;
    std::cout << "EXIT (exit the phonebook)" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 1)
        return 1;

    std::cout << CLEAR;


    PhoneBook book;

    book.Add("John", "Doe", "1234567890");
    book.Add("Jonas", "Kauker", "0987654321");
    book.Add("Leon", "Zipp", "5474567445");
    book.Add("Max", "Mustermann", "1234567890");
    book.Add("Alex", "Terrible", "2474275774");
    book.Add("Peter", "Schmidt", "054789234");
    book.Add("Hans", "Müller", "1234567890");
    book.Add("Klaus", "Schulze", "1234567890");

    std::cout << CLEAR;
    std::cout << "Welcome to the " << &argv[0][2] << "!" << std::endl;

    while(true)
    {
        PrintCommans();

        std::cout << "Enter a command: ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "ADD")
            book.Add();
        else if (input == "SEARCH")
            book.Search();
        else if (input == "EXIT")
            break;
        else
            std::cout << "Invalid command: " << input << std::endl;
    }
    return 0;
}