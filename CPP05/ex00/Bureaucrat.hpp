/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:03 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/02 17:33:09 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>



class Bureaucrat
{
	private:
		const std::string _name;
		unsigned short _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(unsigned short grade, std::string name);
		Bureaucrat(unsigned short grade);
		Bureaucrat(const Bureaucrat &creat);
		Bureaucrat operator=(const Bureaucrat &ther);
		std::string getName() const;
		unsigned short getGrade() const;
		class GradeTooHighExcetion : std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return "Grade is too high!";
				}
		};
		class GradeTooLowExcetion : std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return "Grade is too low!";
				}
		};

};