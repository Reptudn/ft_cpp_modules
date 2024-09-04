/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 16:33:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

AForm *createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPresedential(std::string target)
{
	return new PresidentialPardonForm(target);
}

typedef AForm* (*FormCreator)(std::string);

std::string options[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
FormCreator formCreators[] = {createPresedential, createRobotomy, createShrubbery};

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (options[i] == form_name)
		{
			std::cout << "Intern creates " + form_name + " form" << std::endl;
			return formCreators[i](target);
		}
	}
	return nullptr;
}