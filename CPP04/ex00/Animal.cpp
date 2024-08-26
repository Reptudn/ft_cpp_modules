/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:42:32 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:33:31 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::~Animal()
{
	std::cout << "Animal Destructor called!" << std::endl;
}

Animal::Animal() : type("Animal"), name("Random")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string name, std::string type) : type(type), name(name)
{
	std::cout << "Animal Name and Type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->name = animal.getName();
	this->type = animal.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &animal) return *this;

	this->name = animal.getName();
	this->type = animal.getType();
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Random animal sound" << std::endl;
}

std::string Animal::getName() const
{
	return this->name;
}

std::string Animal::getType() const
{
	return this->type;
}
