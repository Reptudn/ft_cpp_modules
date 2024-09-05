/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/05 12:47:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

int main()
{
	try
	{
		
		Bureaucrat a = Bureaucrat(1, "Peter");
		Bureaucrat b = Bureaucrat(100, "Hans");

		PresidentialPardonForm p = PresidentialPardonForm("42");
		RobotomyRequestForm r = RobotomyRequestForm("Optimus Prime");
		ShrubberyCreationForm s = ShrubberyCreationForm("Field");

		a.signForm(p);
		p.execute(a);

		r.execute(a);

		a.signForm(r);
		r.execute(a);

		a.signForm(s);
		s.execute(a);

	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}