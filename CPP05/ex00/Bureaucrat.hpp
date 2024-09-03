/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:03 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/03 08:40:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>

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

};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &crat);