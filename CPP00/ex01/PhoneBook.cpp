/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:24:05 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 09:24:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <ostream>


PhoneBook::PhoneBook() {
	count = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add(std::string name, std::string surname, std::string phone_number, std::string secret, std::string nickname)
{

	for (int i = 0; phone_number[i]; i++)
	{
		if (phone_number[i] < '0' || phone_number[i] > '9')
		{
			std::cout << "Error: phone number must contain only digits" << std::endl;
			return;
		}
	}

	if (count >= 8)
	{
		Contact oldest = GetOldestContact();
		int	oldestIndex = GetContactIndex(oldest);
		if (oldestIndex < 0)
			std::cout << "Error: oldest contact not found" << std::endl;
		else contacts[oldestIndex].SetContact(name, surname, phone_number, secret, nickname);
	}
	else contacts[count++].SetContact(name, surname, phone_number, secret, nickname);
	std::cout << "Total contacts in phonebook " << count << "/8\n" << std::endl;
}

void PhoneBook::Add()
{
	if (count >= 8)
	{
		Contact oldest = GetOldestContact();
		int	oldestIndex = GetContactIndex(oldest);
		if (oldestIndex < 0)
			std::cout << "Error: oldest contact not found" << std::endl;
		else contacts[oldestIndex].SetContact();
	}
	else contacts[count++].SetContact();
	std::cout << "Total contacts in phonebook " << count << "/8\n" << std::endl;
}

void PhoneBook::Search()
{
	std::string keyword;
	std::cout << "Enter search keyword: ";
	std::getline(std::cin, keyword);
	std::cout << std::endl;
	std::string indexes = "";

	int found = 0;
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|  index   |   name   |  surname | nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (unsigned int i = 0; i < count; i++)
	{
		if (contacts[i].is_empty) // continues if the contact is empty
			continue;
		if (contacts[i].GetName().find(keyword) != std::string::npos || // if the keyword is found in any of the contact fields
			contacts[i].GetSurname().find(keyword) != std::string::npos ||
			contacts[i].GetPhoneNumber().find(keyword) != std::string::npos ||
			contacts[i].GetSecret().find(keyword) != std::string::npos ||
			contacts[i].GetNickname().find(keyword) != std::string::npos)
		{
			contacts[i].PrintContact(found++);
			indexes += std::to_string(i);
		}
		else if (keyword.length() == 1 && (keyword[0] - '0') == (int)i)
		{
			contacts[i].PrintContact(found++);
			indexes += std::to_string(i);
		}
	}
	if (found == 0)
		std::cout << "|             No contacts found             |" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	if (found > 0)
	{
		std::string index;
		std::cout << "Enter index to view contact details: ";
		std::getline(std::cin, index);
		if (index.length() == 1 && index[0] > '0' && index[0] <= '8' && index[0] <= found + '0')
		{
			int index_s = indexes[index[0] - '0' - 1] - '0';
			if (contacts[index_s].is_empty)
				std::cout << "Error: contact is empty\n" << std::endl;
			else contacts[index_s].PrintContact();
		}
		else if (std::cin.eof())
		{
			std::cout << "Canceled search\n" << std::endl;
		}
		else std::cout << "Error: invalid index\n" << std::endl;
	}
}

Contact PhoneBook::GetOldestContact()
{
	Contact oldest = PhoneBook::contacts[0];
	for (unsigned int i = 0; i < count; i++)
	{
		if (contacts[i].is_empty)
			continue;
		
		if (contacts[i].create_timestamp < oldest.create_timestamp)
		{
			oldest = contacts[i];
		}
	}
	return oldest;
}

int PhoneBook::GetContactIndex(Contact& contact)
{
	for (unsigned int i = 0; i < count; i++)
	{
		if (contacts[i].GetName() == contact.GetName() &&
			contacts[i].GetSurname() == contact.GetSurname() &&
			contacts[i].GetPhoneNumber() == contact.GetPhoneNumber() &&
			contacts[i].GetSecret() == contact.GetSecret() &&
			contacts[i].GetNickname() == contact.GetNickname())
		{
			return i;
		}
	}
	return -1;
}
