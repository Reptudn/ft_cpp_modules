/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:03 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 13:29:22 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _execute_grade;
	public:
		Form();
		~Form();
		Form(const Form &form);
		Form(std::string name, int sign_grade, int execute_grade);
		Form &operator=(const Form &form);
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
		void beSigned(const Bureaucrat &crat);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
};

std::ostream &operator<<(std::ostream &stream, const Form &form);