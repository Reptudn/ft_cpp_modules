#pragma once

#include <filesystem>
#include <iostream>
#include <vector>
#include <ctime>
#include <utility>

class BitcoinExchange
{
	private:
		std::string _filename;
		std::vector<std::pair<std::tm, float>> _data;

		bool isFileValid() const;
	public:
		BitcoinExchange(std::string filepath);
		~BitcoinExchange();
		void printExchange() const;
};