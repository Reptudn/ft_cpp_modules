#include "PhoneBook.hpp"

class Contact
{
	public:
		std::string	name = "";
		std::string	surname = "";
		std::string	phone_number = "";
		time_t		create_timestamp = -1;
		bool		is_empty = true;

		Contact() : is_empty(true) {}

		Contact(std::string name = "", std::string = "", std::string phone_number = "") : is_empty(false) {
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