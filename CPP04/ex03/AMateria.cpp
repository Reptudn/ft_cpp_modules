/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:26:31 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 10:08:51 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria name constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &mat)
{
	this->_type = mat.getType();
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &mat)
{
	std::cout << "AMateria assignment overload called" << std::endl;
	if (this == &mat) return *this;
	this->_type = mat.getType();
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

// would work if this class wouldnt be an interface
// AMateria *AMateria::clone() const
// {
// 	return new AMateria(*this);
// }

void AMateria::use(ICharacter &target)
{
	std::cout << _type + " was used on " + target.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const AMateria &mat)
{
	return (stream << mat.getType());
}