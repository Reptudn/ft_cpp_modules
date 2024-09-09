/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:32:33 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/09 10:11:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		static bool isOnlyDisplayable(std::string val);
		static bool isInBounds(std::string val, std::string type);
	public:
		static void convert(std::string val);
};