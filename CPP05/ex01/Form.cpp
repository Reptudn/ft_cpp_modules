/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 13:57:35 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _sign_grade(100), _execute_grade(50)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &form) : _name(std::string(form._name)), _signed(form._signed), _sign_grade(form._sign_grade), _execute_grade(form._execute_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << "Form custom Form construcor called" << std::endl;

	if (sign_grade < 1 || execute_grade < 1) throw Form::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150) throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &form)
{
	std::cout << "Form assignment oeprator called" << std::endl;
	if (this == &form) return *this;
	_signed = form._signed;
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return _sign_grade;
}

int Form::getExecuteGrade() const
{
	return _execute_grade;
}

bool Form::isSigned() const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat &crat)
{
	if (crat.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << "Form Name: " << form.getName() << std::endl;
	stream << "Currently signed? " << (form.isSigned() ? "Yes" : "No") << std::endl;
	stream << "Grade needed to sign: " << form.getSignGrade() << std::endl;
	stream << "Grade needed to execute: " << form.getExecuteGrade() << std::endl;
	return (stream);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for the form!");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for the form!");
};