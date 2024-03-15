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
				int	oldestIndex = getContactIndex(oldest);
				if (oldestIndex < 0)
				{
					std::cout << "Error: oldest contact not found" << std::endl;
					return;
				}
				contacts[oldestIndex] = contact;
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
			for (Contact contact : contacts)
			{
				if (contact.is_empty)
					continue;

				if (contact.name.find(keyword) != std::string::npos ||
					contact.surname.find(keyword) != std::string::npos ||
					contact.phone_number.find(keyword) != std::string::npos)
				{
					contact.printContact();
				}
			}
			std::cout << std::endl;
		}

		Contact& getOldestContact()
		{
			Contact& oldest = contacts[0];
			for (Contact contact : contacts)
			{
				if (contact.is_empty)
					continue;
				
				if (contact.create_timestamp < oldest.create_timestamp)
				{
					oldest = contact;
				}
			}
			return oldest;
		}

		int	getContactIndex(const Contact& contact)
		{
			for (int i = 0; i < count; i++)
			{
				if (contacts[i].name == contact.name &&
					contacts[i].surname == contact.surname &&
					contacts[i].phone_number == contact.phone_number)
				{
					return i;
				}
			}
			return -1;
		}
};