#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <regex>

BitcoinExchange::BitcoinExchange(std::string filename)
{
	_filename = filename;
	if (!isFileValid("data.csv", std::regex(R"(\d{4}-\d{2}-\d{2},\d+(\.\d*)?(\r?\n)?$)")))
		throw std::runtime_error("There is an error with the db file.");
	else
	 	std::cout << "File db: OK!" << std::endl;
	
	if (!isFileValid(filename, std::regex(R"(\d{4}-\d{2}-\d{2} \| \d+(\.\d+)?$)")))
		throw std::runtime_error("There is an error with the input file.");
	else
	 	std::cout << "File input: OK!" << std::endl;

	int i = 0;
	std::string line;
	std::fstream file(_filename);
	while (std::getline(file, line))
	{
		if (i == 0) continue;

		std::string date = line.substr(0, 10);
		std::string value = line.substr(11, line.size());
		std::tm tm = {};
		strptime(date.c_str(), "%Y-%m-%d", &tm);
		_data.push_back(std::make_pair(tm, std::stof(value)));

		i++;
	}
}

void BitcoinExchange::printExchange() const
{
	
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isFileValid(std::string filename, std::regex pattern) const
{
	std::ifstream file(filename);
	if (!file.is_open() || !file.good())
	{
		std::cerr << "Error: File " << filename << " does not exist." << std::endl;
		return false;
	}

	int i = 0;
	std::string line;
	while (std::getline(file, line))
	{
		// std::cout << "Line " << i << ": " << line << std::endl;
		if (i != 0 && !std::regex_match(line, pattern))
		{
			std::cerr << " doesn't match the right format" << std::endl;
			file.close();
			return false;
		}
		i++;
	}
	file.close();
	return true;
}

