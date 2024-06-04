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

    // book.Add("John", "Doe", "234567890", "I am John Doe", "JD");
    // book.Add("Jonas", "Kauker", "098765432", "I am Jonas Kauker", "github.com/Reptudn");
    // book.Add("Leon", "Zipp", "5474567445", "go lang best lang", "amogus");
    // book.Add("Max", "Mustermann", "234567890", "I am Max Mustermann", "MM");
    // book.Add("Alex", "Terrible", "12474275774", "I am Alex Terrible", "AT");
    // book.Add("Peter", "Schmidt", "054789234", "I am Peter Schmidt", "PS");
    // book.Add("Hans", "Mueller", "234567890", "I am Hans Müller", "HM");
    // book.Add("Klaus", "Schulze", "234567890", "I am Klaus Schulze", "KS");

    // book.Add("A", "B", "1234567890", "I am A B", "AB");
    // book.Add("C", "D", "0987654321", "I am C D", "CD");
    // book.Add("E", "F", "5474567445", "I am E F", "EF");
    // book.Add("G", "H", "1234567890", "I am G H", "GH");
    // book.Add("I", "J", "2474275774", "I am I J", "IJ");
    // book.Add("K", "L", "054789234", "I am K L", "KL");
    // book.Add("M", "N", "1234567890", "I am M N", "MN");
    // book.Add("O", "P", "1234567890", "I am O P", "OP");

    std::cout << CLEAR;
    std::cout << "Welcome to the " << &argv[0][2] << "!\n" << std::endl;

    while(42 == 42)
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
        else if (std::cin.eof())
            break;
        else
            std::cout << "Invalid command: '" << (input.empty() ? "<empty>" : input) << "'" << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;
    return 0;
}
