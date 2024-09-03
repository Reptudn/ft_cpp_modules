/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 13:39:07 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
	{

		try
		{
			
			Bureaucrat a = Bureaucrat(12, "Peter");

			Bureaucrat b = Bureaucrat(1, "Hans");

			std::cout << a << std::endl;

			Bureaucrat c = Bureaucrat(160, "Stefan");

		}
		catch (Bureaucrat::GradeTooHighException &ex)
		{
			std::cout << "Grade too high error: " << ex.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &ex)
		{
			std::cout << "Grade too low error: " << ex.what() << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "Error: " << ex.what() << std::endl;
		}
		
	}

	std::cout << "\n\n\n---------------------\n" << std::endl;

	{
		try
		{
			Bureaucrat a = Bureaucrat(1, "Hans");
			a.increaseGrade();
		}
		catch (Bureaucrat::GradeTooHighException &ex)
		{
			std::cout << "Grade too high error: " << ex.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &ex)
		{
			std::cout << "Grade too low error: " << ex.what() << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "Error: " << ex.what() << std::endl;
		}
		
	}

	std::cout << "\n\n\n---------------------\n" << std::endl;

	{
		try
		{
			Bureaucrat a = Bureaucrat(150, "Hans");
			a.decrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &ex)
		{
			std::cout << "Grade too high error: " << ex.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &ex)
		{
			std::cout << "Grade too low error: " << ex.what() << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cout << "Error: " << ex.what() << std::endl;
		}
	}

	return 0;
}