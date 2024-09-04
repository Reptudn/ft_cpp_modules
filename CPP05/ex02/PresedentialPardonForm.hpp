/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresedentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:52 by jkauker           #+#    #+#             */
/*   Updated: 2024/09/04 10:50:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		void execute(Bureaucrat const &executor) const;
};