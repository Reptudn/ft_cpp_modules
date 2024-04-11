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
	if (count >= 8)
	{
		Contact oldest = GetOldestContact();
		int	oldestIndex = GetContactIndex(oldest);
		if (oldestIndex < 0)
			std::cout << "Error: oldest contact not found" << std::endl;
		else contacts[oldestIndex].SetContact(name, surname, phone_number, secret, nickname);
	}
	else contacts[count++].SetContact(name, surname, phone_number, secret, nickname);
	std::cout << "Contact count: " << count << std::endl;
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
	std::cout << "Contact count: " << count << std::endl;
}

// TODO: Make the contacts display like it says in the assignment
void PhoneBook::Search()
{
	std::string keyword;
	std::cout << "Enter search keyword: ";
	std::getline(std::cin, keyword);
	std::cout << std::endl;

	int found = 0;
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|  index   |   name   |  surname | nickname |" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	for (unsigned int i = 0; i < count; i++)
	{
		if (contacts[i].is_empty)
			continue;
		if (contacts[i].GetName().find(keyword) != std::string::npos ||
			contacts[i].GetSurname().find(keyword) != std::string::npos ||
			contacts[i].GetPhoneNumber().find(keyword) != std::string::npos ||
			contacts[i].GetSecret().find(keyword) != std::string::npos ||
			contacts[i].GetNickname().find(keyword) != std::string::npos)
		{
			contacts[i].PrintContact(found);
			found++;
		}
	}
	if (found == 0)
		std::cout << "|             No contacts found             |" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
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