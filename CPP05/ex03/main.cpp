/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:30:44 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 13:23:26 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <exception>

int main()
{
	try
	{
		
		Bureaucrat a = Bureaucrat(1, "Peter");
		Bureaucrat b = Bureaucrat(100, "Hans");

		Intern someRandomIntern;
		AForm *internForm;

		internForm = someRandomIntern.makeForm("presidential pardon", "Steve");

		if (internForm)
		{
			b.signForm(*internForm);
			internForm->execute(b);

			delete internForm;
		}

		PresidentialPardonForm p = PresidentialPardonForm();
		RobotomyRequestForm r = RobotomyRequestForm();
		ShrubberyCreationForm s = ShrubberyCreationForm();

		a.signForm(p);
		p.execute(a);

		r.execute(a);

		a.signForm(r);
		r.execute(a);

		a.signForm(s);
		s.execute(a);

	}
	catch (Bureaucrat::GradeTooHighException &ex)
	{
		std::cout << "Grade too high error: " << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex)
	{
		std::cout << "Grade too low error: " << ex.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &ex)
	{
		std::cout << "Form grade too low error: " << ex.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &ex)
	{
		std::cout << "Form grade too high error: " << ex.what() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}