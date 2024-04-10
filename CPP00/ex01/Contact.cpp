/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:23:28 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 09:23:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <ctime>

Contact::Contact() : name(""), surname(""), phone_number(""), create_timestamp(-1), is_empty(true) {}

Contact::~Contact() {}

void Contact::SetContact()
{
	std::cout << "Enter name: ";
	std::getline(std::cin, name);
	std::cout << "Enter surname: ";
	std::getline(std::cin, surname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	create_timestamp = std::time(0);
	is_empty = false;
	std::cout << "Contact created!" << std::endl;
	Contact::PrintContact();
}

void Contact::SetContact(std::string name, std::string surname, std::string phone_number)
{
	Contact::name = name;
	Contact::surname = surname;
	Contact::phone_number = phone_number;
	create_timestamp = std::time(0);
	is_empty = false;
	std::cout << "Contact created!" << std::endl;
	Contact::PrintContact();
}

void Contact::PrintContact()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Surname: " << surname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Created: " << std::ctime(&create_timestamp) << std::endl;
}

std::string Contact::GetName() const
{
	return Contact::name;
}

std::string Contact::GetSurname() const
{
	return Contact::surname;
}

std::string Contact::GetPhoneNumber() const
{
	return Contact::phone_number;
}
