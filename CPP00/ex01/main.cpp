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

int main(int argc, char **argv)
{
    if (argc != 1)
        return 1;

    std::cout << "Welcome to the " << argv[0] << "!" << std::endl;

    PhoneBook book;

    while(true)
    {
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