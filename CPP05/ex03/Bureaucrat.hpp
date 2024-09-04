/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:03 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 15:24:20 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &creat);
		Bureaucrat &operator=(const Bureaucrat &ther);
		std::string getName() const;
		int getGrade() const;
		void increaseGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		void signForm(AForm &form);
		void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &crat);