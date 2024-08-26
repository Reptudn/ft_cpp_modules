/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:15:05 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 10:14:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <ostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	std::cout << "Cure copy constructor called called" << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "Cure: '* heals " + target.getName() + "`s wounds *'" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

std::ostream &operator<<(std::ostream &stream, const Cure &cure)
{
	return (stream << cure.getType());
}