/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 10:32:04 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("random"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("random")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	else if (grade < 1) throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat construction complete." << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	else if (grade < 1) throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat construction complete." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &crat)
{
	std::cout << "Bureaucrat assignnment overload called!" << std::endl;
	if (this == &crat) return *this;
	this->_grade = crat.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &crat) : _name(crat.getName()), _grade(crat.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " + _name << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &crat)
{
	return (stream << crat.getName() + ", bureaucrat grade" << crat.getGrade());
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
};

void Bureaucrat::increaseGrade()
{
	if (_grade - 1 < 1) throw Bureaucrat::GradeTooLowException();
	else _grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150) throw Bureaucrat::GradeTooHighException();
	else _grade++;
}