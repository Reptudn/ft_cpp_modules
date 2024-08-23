/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:15:05 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 09:29:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <ostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice) { }

void Ice::use(ICharacter &target)
{
	std::cout << "Ice: '* shoots ice bolt at " + target.getName() + " *'" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

std::ostream &operator<<(std::ostream &stream, const Ice &ice)
{
	return (stream << ice.getType());
}