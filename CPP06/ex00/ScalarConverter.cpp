/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:36:11 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/09 12:24:06 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

bool ScalarConverter::isOnlyDisplayable(std::string val)
{
	for (char c : val)
	{
		if (c < 32 || c > 126)
			return false;
	}
	return true;
}

bool ScalarConverter::isInBounds(std::string val, std::string type)
{
	if (type == "char")
	{
		try
		{
			int i = std::stoi(val);
			if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
				return false;
			return true;
		}
		catch(const std::exception& e)
		{
			(void)e;
			return false;
		}
	}
	else if (type == "int")
	{
		try
		{
			long i = std::stol(val);
			if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
				return false;
			return true;
		}
		catch(const std::exception& e)
		{
			(void)e;
			return false;
		}
	}
	else if (type == "float")
	{
		try
		{
			float f = std::stof(val);
			if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
				return false;
			return true;
		}
		catch(const std::exception& e)
		{
			(void)e;
			return false;
		}
	}
	else if (type == "double")
	{
		try
		{
			double d = std::stod(val);
			if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
				return false;
			return true;
		}
		catch(const std::exception& e)
		{
			(void)e;
			return false;
		}
	}
	else
	{
		std::cout << "Invalid type!" << std::endl;
		return false;
	}
}

void ScalarConverter::convert(std::string val)
{
	if (!isOnlyDisplayable(val))
	{
		std::cout << "The given string doesn't include only displayable characters!" << std::endl;
		return;
	}
	
	if (val == "nan" || val == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	else if (val == "inf" || val == "inff" || val == "+inf" || val == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return;
	}
	else if (val == "-inf" || val == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	
	if (!isInBounds(val, "char"))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = std::stoi(val);
		std::cout << "char: " << ((c < 32 || c > 126) ? '*' : c) << std::endl;
	}

	if (!isInBounds(val, "int"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << std::stoi(val) << std::endl;

	if (!isInBounds(val, "float"))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::showpoint << std::stof(val) << "f" << std::endl;
	
	if (!isInBounds(val, "double"))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::showpoint << std::stod(val) << std::endl;
}