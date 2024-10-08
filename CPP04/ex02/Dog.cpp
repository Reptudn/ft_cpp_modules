/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:21 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 11:29:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog() : Animal("Random", "Dog")
{
	this->brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name, "Dog")
{
	this->brain = new Brain();
	std::cout << "Dog Name constructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->getName() << ": Wooof!" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &dog) return *this;

	this->name = std::string(dog.getName());
	this->type = std::string(dog.getType());
	return *this;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	this->name = std::string(dog.getName());
	this->type = std::string(dog.getType());
	if (this->brain) delete this->brain;
	this->brain = new Brain(*dog.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

std::string Dog::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "Invalid idea index (0 - 99)" << std::endl;
		return "";
	}
	return this->brain->ideas[idx];
}