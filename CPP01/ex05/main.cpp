#include "Harl.hpp"

int main()
{
	Harl harl = Harl();

	std::string line;
	std::cout << "\nEnter a Harl loglevel: ";
	while (std::getline(std::cin, line))
	{
		harl.complain(line);
		std::cout << "\nEnter a Harl loglevel: ";
	}
}