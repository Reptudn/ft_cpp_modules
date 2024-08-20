/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:34:49 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/20 12:50:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Random", "WrongCat")
{
	std::cout << "Wrong cat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name, "WrongCat")
{
	std::cout << "Wrong cat name constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	this->name = cat.getName();
	this->type = cat.getType();
	std::cout << "Wrong cat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &animal)
{
	std::cout << "Wrong cat assignment operator overload called" << std::endl;
	if (this == &animal) return *this;

	this->name = animal.getName();
	this->type = animal.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sounds" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, WrongCat &animal)
{
	return (stream << animal.getName());
}