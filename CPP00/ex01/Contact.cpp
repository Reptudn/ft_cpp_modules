#include "PhoneBook.hpp"

class Contact
{
	public:
		std::string	name;
		std::string	surname;
		std::string	phone_number;
		time_t		create_timestamp;

		Contact(std::string name = "", std::string = "", std::string phone_number = "") {
			this->name = name;
			this->surname = surname;
			this->phone_number = phone_number;
			this->create_timestamp = std::time(0);
		}

		void printContact()
		{
			std::cout << "Name: " << name << std::endl;
			std::cout << "Surname: " << surname << std::endl;
			std::cout << "Phone number: " << phone_number << std::endl;
			std::cout << "Created: " << std::ctime(&create_timestamp) << std::endl;
		}

};