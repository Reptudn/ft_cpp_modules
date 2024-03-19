#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string	name = "";
		std::string	surname = "";
		std::string	phone_number = "";

	public:
		time_t		create_timestamp = -1;
		bool		is_empty = true;

		Contact() : is_empty(true) {}

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

};