/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 14:58:22 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _execute_grade;
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &form);
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm &operator=(const AForm &form);
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
		virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);