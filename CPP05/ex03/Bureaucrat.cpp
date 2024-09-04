/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 10:38:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("random"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("random")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	else if (grade < 1) throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat construction complete." << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150) throw Bureaucrat::GradeTooHighException();
	else if (grade < 1) throw Bureaucrat::GradeTooLowException();
	_grade = grade;
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
	return (stream << crat.getName() + ", bureaucrat grade " << crat.getGrade());
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

void Bureaucrat::signForm(AForm &form)
{
	std::cout << getName() << " is trying to sign " << form.getName() << std::endl;
	try
	{
		if (form.isSigned())
		{
			std::cout << "Form " + form.getName() << " is already signed" << std::endl;
			return;
		}

		form.beSigned(*this);
		std::cout << _name + " signed " + form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << _name + " couldn't sign " + form.getName() + ", because " << e.what() << std::endl;
	}
	catch(AForm::GradeTooHighException &e)
	{
		std::cout << _name + " couldn't sign " + form.getName() + ", because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		std::cout << getName() + " is trying to execute " + form.getName() << std::endl;
		form.execute(*this);
		std::cout << getName() + " successfully to executed " + form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &ex)
	{
		std::cout << getName() + " failed to execute " + form.getName() + ", because " << ex.what() << std::endl;
	}
}