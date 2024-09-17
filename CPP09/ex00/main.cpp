#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc(argv[1]);
		btc.printExchange();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}