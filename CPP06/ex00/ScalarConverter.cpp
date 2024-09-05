/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:36:11 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/05 09:49:50 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

bool isOnlyDisplayable(std::string val)
{
	for (char c : val)
	{
		if (c < 32 || c > 126)
			return false;
	}
	return true;
}

void ScalarConverter::convert(std::string val)
{
	if (!isOnlyDisplayable(val))
	{
		std::cout << "The given string doesn't include only displayable characters!" << std::endl;
		return;
	}
	
	char c = std::stoi(val);
	int i = std::stoi(val);
	float f = std::stof(val);
	double d = std::stod(val);

	std::cout << "char: " << ((c < 32 || c > 126) ? '*' : c) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}