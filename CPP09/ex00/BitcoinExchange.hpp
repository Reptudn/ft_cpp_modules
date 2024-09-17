#pragma once

#include <filesystem>
#include <iostream>
#include <vector>
#include <ctime>
#include <utility>
#include <regex>

class BitcoinExchange
{
	private:
		std::string _filename;
		std::string _db;
		std::vector<std::pair<std::tm, float>> _data;

		bool isFileValid(std::string filename, std::regex pattern) const;
	public:
		BitcoinExchange(std::string filepath);
		~BitcoinExchange();
		void printExchange() const;
};