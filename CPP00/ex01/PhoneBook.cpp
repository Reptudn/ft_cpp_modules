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


PhoneBook::PhoneBook() {
	count = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add()
{
	if (count >= 8)
	{
		Contact& oldest = getOldestContact();
		int	oldestIndex = getContactIndex(oldest);
		if (oldestIndex < 0)
			std::cout << "Error: oldest contact not found" << std::endl;
		else contacts[oldestIndex].setContact();
	}
	else contacts[count].setContact();
}

void PhoneBook::Search()
{
	std::string keyword;
	std::cout << "Enter keyword: ";
	std::getline(std::cin, keyword);
	std::cout << std::endl;
	for (unsigned int i = 0; i < count; i++)
	{
		if (contacts[i].is_empty)
			continue;
		if (contacts[i].GetName().find(keyword) != std::string::npos ||
			contacts[i].GetSurname().find(keyword) != std::string::npos ||
			contacts[i].GetPhoneNumber().find(keyword) != std::string::npos)
		{
			contacts[i].printContact();
		}
	}
	std::cout << std::endl;
}

// class PhoneBook
// {
// 	public:
// 		Contact					contacts[8];
// 		unsigned int			count;
		
// 		PhoneBook() : count(0) {}

		Contact& PhoneBook::GetOldestContact()
		{
			Contact& oldest = contacts[0];
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

		int PhoneBook::GetContactIndex(const Contact& contact)
		{
			for (unsigned int i = 0; i < count; i++)
			{
				if (contacts[i].GetName() == contact.GetName() &&
					contacts[i].GetSurname() == contact.GetSurname() &&
					contacts[i].GetPhoneNumber() == contact.GetPhoneNumber())
				{
					return i;
				}
			}
			return -1;
		}