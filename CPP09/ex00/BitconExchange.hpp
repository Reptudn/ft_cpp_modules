#pragma once

#include <filesystem>
#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::string _filename;
		std::map<std::string, float> _data;

		bool isFileValid() const;
	public:
		BitcoinExchange(std::string filepath);
		~BitcoinExchange();
		void printExchange() const;
};