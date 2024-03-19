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

// #include "Contact.hpp"

#include <iostream>
#include <string>
#include <ctime>

class Contact
{
	private:
		std::string	name;
		std::string	surname;
		std::string	phone_number;

	public:
		time_t		create_timestamp;
		bool		is_empty;

		Contact() :  name(""), surname(""), phone_number(""), create_timestamp(-1), is_empty(true) {}

		void setContact()
		{
			std::cout << "Enter name: ";
			std::getline(std::cin, name);
			std::cout << "Enter surname: ";
			std::getline(std::cin, surname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phone_number);
			create_timestamp = std::time(0);
			is_empty = false;
		}

		void printContact()
		{
			std::cout << "Name: " << name << std::endl;
			std::cout << "Surname: " << surname << std::endl;
			std::cout << "Phone number: " << phone_number << std::endl;
			std::cout << "Created: " << std::ctime(&create_timestamp) << std::endl;
		}

		std::string GetName() const
		{
			return name;
		}

		std::string GetSurname() const
		{
			return surname;
		}

		std::string GetPhoneNumber() const
		{
			return phone_number;
		}

};