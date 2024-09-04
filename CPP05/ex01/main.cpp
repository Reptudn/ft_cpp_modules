/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 16:00:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	try
	{
		
		Bureaucrat a = Bureaucrat(12, "Peter");
		Bureaucrat b = Bureaucrat(100, "Hans");
		Form form = Form("Important form", 20, 5);
		Form form2 = Form("Cringe", 60, 20);

		std::cout << a << std::endl;
		std::cout << form << std::endl;

		a.signForm(form);
		b.signForm(form);
		std::cout << a << std::endl;

		b.signForm(form2);

	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}