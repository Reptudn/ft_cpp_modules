/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 16:34:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		AForm *makeForm(std::string form_name, std::string target);
};