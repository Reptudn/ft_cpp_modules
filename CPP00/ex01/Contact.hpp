/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:49:47 by jkauker           #+#    #+#             */
/*   Updated: 2024/04/10 08:37:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <ctime>

class Contact
{
	public:
		Contact();
		~Contact();
		
	private:
		std::string	name;
		std::string	surname;
		std::string	phone_number;

	public:
		time_t		create_timestamp;
		bool		is_empty;

		void SetContact();
		void SetContact(std::string name, std::string surname, std::string phone_number);
		void PrintContact();
		std::string GetName() const;
		std::string GetSurname() const;
		std::string GetPhoneNumber() const;
};

#endif