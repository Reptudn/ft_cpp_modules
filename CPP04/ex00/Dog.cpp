/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:21 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:30:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog() : Animal("Random", "Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name, "Dog")
{
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

	this->name = dog.getName();
	this->type = dog.getType();
	return *this;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	this->name = dog.getName();
	this->type = dog.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}