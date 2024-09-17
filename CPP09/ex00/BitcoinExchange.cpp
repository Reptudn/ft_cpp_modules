#include "BitcoinExchange.hpp"
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

bool BitcoinExchange::isFileValid() const
{
	std::fstream file;
	file.open(_filename, std::ios::in);
	if (!file.is_open() || !file.good())
	{
		std::cerr << "Error: File " << _filename << " does not exist." << std::endl;
		return false;
	}

	std::regex pattern(R"(\d{4}-\d{2}-\d{2},\d+(\.\d*)?(\r?\n)?$)");

	// why does this work here but not down in the loop?
	std::string lline = "2009-01-02,0\n";
	if (!std::regex_match(lline, pattern))
	{
		std::cerr << "Error: Line '" + lline + "' doesn't match the right format" << std::endl;
	} else std::cout << "matches the pattern" << std::endl;

	int i = 0;
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << ">" << line << "<";
		if (i != 0 && !line.empty() && !std::regex_match(line, pattern))
		{
			std::cerr << " doesn't match the right format" << std::endl;s
			return false;
		} else std::cerr << " matches the pattern" << std::endl;
		i++;
	}
	return true;
}

