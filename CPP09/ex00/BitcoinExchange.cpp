#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include <iomanip>

// XXX: I check the file before i get the courseand everything
BitcoinExchange::BitcoinExchange(std::string filename)
{
	_filename = filename;
	_db = "data.csv";
	if (!isFileValid("data.csv", std::regex(R"(\d{4}-\d{2}-\d{2},\d+(\.\d*)?(\r?\n)?$)")))
		throw std::runtime_error("There is an error with the db file.");
	// else
	//  	std::cout << "File db: OK!" << std::endl;
	
	if (!isFileValid(filename, std::regex(R"(\d{4}-\d{2}-\d{2} \| \d+(\.\d+)?$)")))
		throw std::runtime_error("There is an error with the input file.");

	try
	{
		loadDbFile();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		throw std::runtime_error("There is an error with the db file.");
	}

	try
	{
		loadInputFile();
		// std::cout << "File input: OK!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		throw std::runtime_error("There is an error with the input file.");
	}

}

void BitcoinExchange::loadInputFile() // YYYY-MM-DD | VALUE
{
	int i = 0;
	std::string line;
	std::fstream file(_filename);
	file.seekg(0, std::ios::beg);
	while (std::getline(file, line))
	{
		if (i++ == 0) continue;

		std::string date = line.substr(0, 10);
		std::string value = line.substr(13, line.size());
		std::tm tm = {};
		strptime(date.c_str(), "%Y-%m-%d", &tm);

		float val = std::stof(value);
		// if (val < 0.0 || val > 1000.0) 
		// {
		// 	file.close();
		// 	throw std::runtime_error("Value out of range");
		// }
		_data.emplace(tm, val, line);
	}
	file.close();
}

void BitcoinExchange::loadDbFile() // YYYY-MM-DD,VALUE
{
	int i = 0;
	std::string line;
	std::fstream file(_db);
	file.seekg(0, std::ios::beg);
	while (std::getline(file, line))
	{
		if (i++ == 0) continue;

		std::string date = line.substr(0, 10);
		std::string value = line.substr(11, line.size());
		std::tm tm = {};
		strptime(date.c_str(), "%Y-%m-%d", &tm);

		float val = std::stof(value);
		_d.emplace((BitcoinData){tm, val, line});
	}
	file.close();
}

bool BitcoinExchange::isSameDate(std::tm date1, std::tm date2) const
{
	return date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday == date2.tm_mday;
}

BitcoinCourse BitcoinExchange::getCourse(std::tm date) const
{
	BitcoinCourse course(date, 0);
	auto it = _d.find(course);
	if (it != _d.end())
		return *it;
	
	auto it2 = _d.lower_bound(course);
	if (it2 == _d.begin() || isSameDate(it2->date, date))
		return *it2;
	
	return *(--it2);
}

void BitcoinExchange::printExchange() const
{
	auto it = _data.begin();
	while (it != _data.end())
	{
		if (!std::regex_match(it->original, std::regex(R"(\d{4}-\d{2}-\d{2} \| \d+(\.\d+)?$)")) || it->value < 0.0 || it->value > 1000.0)
		{
			std::cerr << "Invalid" << std::endl;
			it++;
			continue;
		}

		BitcoinCourse course = getCourse(it->date);

		std::cout << std::put_time(&it->date, "%Y-%m-%d") << " => " << it->value << " = " << std::to_string(it->value * course.value) << std::endl;

		it++;
	}
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
		if (i != 0 && !std::regex_match(line, pattern))
		{
			std::cerr << "INFO: " << line << " doesn't match the right format" << std::endl;
			// file.close();
			// return false;
		}
		i++;
	}
	file.close();
	return true;
}

