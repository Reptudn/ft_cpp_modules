/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:21 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 11:28:12 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat() : Animal("Random", "Cat")
{
	this->brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal(name, "Cat")
{
	this->brain = new Brain();
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

	this->name = std::string(cat.name);
	this->type = std::string(cat.type);
	return *this;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	this->name = std::string(cat.name);
	this->type = std::string(cat.type);
	if (this->brain) delete this->brain;
	this->brain = new Brain(*cat.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

std::string Cat::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "Invalid idea index (0 - 99)" << std::endl;
		return "";
	}
	return this->brain->ideas[idx];
}