/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:03 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 13:26:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include "Form.hpp"

class Form;

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
		class GradeTooHighException : std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : std::exception
		{
			public:
				const char* what() const throw();
		};
		void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &crat);