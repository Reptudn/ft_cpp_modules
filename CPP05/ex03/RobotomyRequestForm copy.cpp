/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 13:09:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestFrom default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestFrom target constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment overload called" << std::endl;
	if (this == &other) return *this;

	this->target = std::string(other.target);
	this->setSigned(other.isSigned());
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	this->target = std::string(form.target);
	this->setSigned(form.isSigned());
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
	{
		std::cout << "This form is not signed and so cannot be executed" << std::endl;
		return;
	}
	if (this->getExecuteGrade() < executor.getGrade())
	{
		std::cout << executor.getName() + " can't execute this form" << std::endl;
		throw AForm::GradeTooLowException();
	}
	
	std::cout << "Drilling sounds..." << std::endl;

	if (rand() % 2)
		std::cout << this->target + " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target + " robotomization failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
