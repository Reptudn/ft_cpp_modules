/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:21 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:37:06 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat() : Animal("Random", "Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name, "Cat")
{
	std::cout << "Cat Name constructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->getName() << ": Meooooww!" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &cat) return *this;

	this->name = cat.getName();
	this->type = cat.getType();
	return *this;
}

Cat::Cat(const Cat &cat)
{
	this->name = cat.getName();
	this->type = cat.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}