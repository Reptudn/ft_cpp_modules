/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 16:48:47 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Form"), _signed(false), _sign_grade(100), _execute_grade(50)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const AForm &form) : _name(std::string(form._name)), _signed(form._signed), _sign_grade(form._sign_grade), _execute_grade(form._execute_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << "Form custom Form construcor called" << std::endl;

	if (sign_grade < 1 || execute_grade < 1) throw AForm::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150) throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
	std::cout << "Form assignment oeprator called" << std::endl;
	if (this == &form) return *this;
	_signed = form._signed;
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return _sign_grade;
}

int AForm::getExecuteGrade() const
{
	return _execute_grade;
}

bool AForm::isSigned() const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat &crat)
{
	if (crat.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	_signed = true;
	target = crat.getName();
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	stream << "Form Name: " << form.getName() << std::endl;
	stream << "Currently signed? " << (form.isSigned() ? "Yes" : "No") << std::endl;
	stream << "Grade needed to sign: " << form.getSignGrade() << std::endl;
	stream << "Grade needed to execute: " << form.getExecuteGrade() << std::endl;
	return (stream);
}

void AForm::execute(Bureaucrat const &exec) const
{
	if (!isSigned())
	{
		std::cout << "Cannot execute unsigned Form!" << std::endl;
		return ;
	}
	if (exec.getGrade() > _execute_grade)
		throw AForm::GradeTooLowException();
	std::cout << "Executed empty Form and nothing happens" << std::endl;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for the form!");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for the form!");
};