#pragma once

#include <filesystem>
#include <iostream>
#include <set>
#include <ctime>
#include <utility>
#include <regex>

typedef struct BitcoinData
{
	std::tm date;
	float value;
	std::string original;
	bool operator<(const BitcoinData &data) const
	{
		time_t t1 = mktime(const_cast<std::tm*>(&date));
		time_t t2 = mktime(const_cast<std::tm*>(&data.date));
		return t1 < t2;
	}
	BitcoinData(std::tm date, float value, std::string line) : date(date), value(value), original(line) {}
} BitcoinData;

typedef struct BitcoinCourse
{
	std::tm date;
	float value;
	bool operator<(const BitcoinCourse &course) const
	{
		time_t t1 = mktime(const_cast<std::tm*>(&date));
		time_t t2 = mktime(const_cast<std::tm*>(&course.date));
		return t1 < t2;
	}
	BitcoinCourse(std::tm date, float value) : date(date), value(value) {}
	BitcoinCourse(const BitcoinData& data) : date(data.date), value(data.value) {}
} BitcoinCourse;

class BitcoinExchange	
{
	private:
		std::string _filename;
		std::string _db;
		std::multiset<BitcoinData> _data;
		std::multiset<BitcoinCourse> _d;

		void loadInputFile();
		void loadDbFile();
		bool isFileValid(std::string filename, std::regex pattern) const;
		bool isSameDate(std::tm date1, std::tm date2) const;
		BitcoinCourse getCourse(std::tm date) const;
	public:
		BitcoinExchange(std::string filepath);
		BitcoinExchange &operator=(const BitcoinExchange &exchange);
		BitcoinExchange(const BitcoinExchange &exchange);
		~BitcoinExchange() = default;
		void printExchange() const;
};