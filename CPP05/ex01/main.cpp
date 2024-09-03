/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 13:56:55 by jkauker          ###   ########.fr       */
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
	catch (Bureaucrat::GradeTooHighException &ex)
	{
		std::cout << "Grade too high error: " << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex)
	{
		std::cout << "Grade too low error: " << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex)
	{
		std::cout << "Form grade too low error: " << ex.what() << std::endl;
	}
	catch (Form::GradeTooHighException &ex)
	{
		std::cout << "Form grade too high error: " << ex.what() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}