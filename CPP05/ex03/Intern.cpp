/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 13:22:56 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this == &intern) return *this;
	return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name == "presidential pardon")
	{
		std::cout << "Intern creates " << form_name << " form" << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (form_name == "robotomy request")
	{
		std::cout << "Intern creates " << form_name << " form" << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (form_name == "shrubbery creation")
	{
		std::cout << "Intern creates " << form_name << " form" << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else
	{
		std::cout << "Intern cannot create " << form_name << " form" << std::endl;
		return nullptr;
	}
}