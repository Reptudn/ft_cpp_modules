/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:42:32 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 09:36:10 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>


Animal::~Animal()
{
	std::cout << "Animal Destructor called!" << std::endl;
}

Animal::Animal() : type("Animal"), name("Random")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string name, std::string type) : type(std::string(type)), name(std::string(name))
{
	std::cout << "Animal Name and Type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->name = std::string(animal.getName());
	this->type = std::string(animal.getType());
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &animal) return *this;

	this->name = std::string(animal.getName());
	this->type = std::string(animal.getType());
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
