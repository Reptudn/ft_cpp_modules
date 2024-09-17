#include "BitconExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <regex>

BitcoinExchange::BitcoinExchange(std::string filename)
{
	_filename = filename;
	if (!isFileValid())
		throw std::runtime_error("There is an error with the file.");
	else
	 	std::cout << "File: OK!" << std::endl;
	
}

void BitcoinExchange::printExchange() const
{
	
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isFileValid() const
{
	std::ifstream file(_filename);
	if (!file.good())
	{
		std::cerr << "Error: File " << _filename << " does not exist." << std::endl;
		return false;
	}

	std::string line;
	std::regex pattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) \| (1000(\.0+)?|[0-9]{1,3}(\.\d+)?))");
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: File " << _filename << " is empty." << std::endl;
			return false;
		}
		if (!std::regex_match(line, pattern))
		{
			std::cerr << "Error: Line '" + line + "' doesn't match the right format" << std::endl;
			return false;
		}
	}
	return true;
}

