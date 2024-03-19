#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <time.h>

class Contact
{
	private:
		std::string	name;
		std::string	surname;
		std::string	phone_number;

	public:
		time_t		create_timestamp;
		bool		is_empty;

		Contact();
		void setContact();
		void printContact();
};

class PhoneBook
{
	public:
		std::array<Contact, 8>	contacts;
		unsigned int			count;

		PhoneBook();
		void	add();
		void	search();
};

#endif