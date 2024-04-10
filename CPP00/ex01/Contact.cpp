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
	SetValue("Enter name", name);
	SetValue("Enter surname", surname);
	SetValue("Enter phone number", phone_number);
	SetValue("Enter secret", secret);
	SetValue("Enter nickname", nickname);

	create_timestamp = std::time(0);
	is_empty = false;
	std::cout << "Contact created!" << std::endl;
	Contact::PrintContact();
}

void Contact::SetContact(std::string name, std::string surname, std::string phone_number, std::string secret, std::string nickname)
{

	if (name.empty() || surname.empty() || phone_number.empty() || secret.empty() || nickname.empty())
	{
		std::cout << "Error: name, surname, phone number, secret, and nickname must not be empty" << std::endl;
		return;
	}

	Contact::name = name;
	Contact::surname = surname;
	Contact::phone_number = phone_number;
	Contact::secret = secret;
	Contact::nickname = nickname;
	create_timestamp = std::time(0);
	is_empty = false;
	std::cout << "Contact created!" << std::endl;
	Contact::PrintContact();
}

// TODO: Make the contact print like in the assignment
void Contact::PrintContact()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Surname: " << surname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Secret: " << secret << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Created: " << std::ctime(&create_timestamp) << std::endl;
}

std::string Contact::PrintTextRow(std::string toPrint)
{
	if (toPrint.length() > 10)
		return toPrint.substr(0, 9) + ".";
	std::string spaces(10 - toPrint.length(), ' ');
	return spaces + toPrint;
}

void Contact::PrintContact(int index) // FIXME: umlaute are two caracters so its not displayed correctly
{
	std::cout << "|         " << index + 1 << "|";
	std::cout << PrintTextRow(name) << "|";
	std::cout << PrintTextRow(surname) << "|";
	std::cout << PrintTextRow(nickname) << "|" << std::endl;
}

void Contact::SetValue(std::string prompt, std::string &value)
{	
	std::cout << prompt << ": ";
	std::getline(std::cin, value);
	while (value.empty())
	{
		std::cout << "Error: " << prompt << " must not be empty" << std::endl;
		std::cout << prompt << ": ";
		std::getline(std::cin, value);
	}
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

std::string Contact::GetSecret() const
{
	return Contact::secret;
}

std::string Contact::GetNickname() const
{
	return Contact::nickname;
}