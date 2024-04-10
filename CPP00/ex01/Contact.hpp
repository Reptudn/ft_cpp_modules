/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:49:47 by jkauker           #+#    #+#             */
/*   Updated: 2024/04/10 16:36:14 by jkauker          ###   ########.fr       */
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
		std::string secret;
		std::string nickname;
		void SetValue(std::string prompt, std::string &value);
		std::string PrintTextRow(std::string toPrint);

	public:
		time_t		create_timestamp;
		bool		is_empty;

		void SetContact();
		void SetContact(std::string name, std::string surname, std::string phone_number, std::string secret, std::string nickname);
		void PrintContact();
		void PrintContact(int index);
		std::string GetName() const;
		std::string GetSurname() const;
		std::string GetPhoneNumber() const;
		std::string GetSecret() const;
		std::string GetNickname() const;
};

#endif