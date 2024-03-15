#include <iostream>
#include <ostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNREADABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (char c : std::string(argv[i]))
			std::cout << (char)toupper(c);
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}