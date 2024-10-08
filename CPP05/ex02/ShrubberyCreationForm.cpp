/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/05 12:49:50 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "Nothing";
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	this->target = other.target;
	this->setSigned(other.isSigned());
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment overload called" << std::endl;
	if (this == &other) return *this;
	this->target = std::string(other.target);
	this->setSigned(other.isSigned());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
	
	std::fstream tree_file;
	tree_file.open((this->target + "_shrubbery").c_str(), std::fstream::out);
	if (tree_file.fail() || tree_file.is_open() == false)
	{
		std::cout << "Error: " << strerror(errno) << std::endl;
		return;
	}

	tree_file << "         #o#\n";
	tree_file << "       ####o#\n";
	tree_file << "      #o# \\#|_#,#\n";
	tree_file << "     ###\\ |/   #o#\n";
	tree_file << "      # {}{      #\n";
	tree_file << "         }{{\n";
	tree_file << "        ,'  `" << std::endl;
	
	tree_file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}