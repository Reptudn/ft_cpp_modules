/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/02 17:33:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("random"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned short grade) : _name("random")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw GradeTooHighException();
	else if (grade < 1) throw GradeTooLowException();
	std::cout << "Bureaucrat construction complete." << std::endl;
}

Bureaucrat::Bureaucrat(unsigned short grade, std::string name) : _name(name)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw GradeTooHighException();
	else if (grade < 1) throw GradeTooLowException();
	std::cout << "Bureaucrat construction complete." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &crat) : _name(crat.getName()), _grade(crat.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned short Bureaucrat::getGrade() const
{
	return _grade;
}