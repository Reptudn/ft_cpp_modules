#include <array>
#include <vector>

#include "PhoneBook.hpp"

class PhoneBook
{
	public:
		Contact					contacts[8];
		unsigned int			count;
		
		PhoneBook() : count(0) {}

		void add(const Contact& contact)
		{
			if (count >= 8)
			{
				Contact& oldest = getOldestContact();
			}
			else
			{
				contacts[count] = contact;
				count++;
			}
		}

		void search(std::string keyword)
		{
			std::cout << "SEARCH for " + keyword << std::endl;
			for (Contact c : contacts)
			{
				// not mine so rewrite this
				if (c.name.find(keyword) != std::string::npos ||
					c.surname.find(keyword) != std::string::npos ||
					c.phone_number.find(keyword) != std::string::npos)
				{
					c.PrintContact();
				}
			}
			std::cout << std::endl;
		}

		Contact& getOldestContact()
		{
			
		}
};