/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 08:46:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	try
	{
		
		Bureaucrat a = Bureaucrat(12, "Peter");

		Bureaucrat b = Bureaucrat(1, "Hans");

		Bureaucrat c = Bureaucrat(160, "Stefan");

	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}