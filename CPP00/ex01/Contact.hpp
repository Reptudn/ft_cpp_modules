/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:49:47 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 09:49:48 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <ctime>

class Contact
{
	private:
		static std::string	name;
		static std::string	surname;
		static std::string	phone_number;

	public:
		time_t		create_timestamp;
		bool		is_empty;

		Contact();
		void setContact();
		void printContact();
		std::string GetName() const;
		std::string GetSurname() const;
		std::string GetPhoneNumber() const;
};

#endif