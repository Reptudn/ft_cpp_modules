/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:19:14 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 09:45:44 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal() : type("Wrong Animal"), name("Random")
{
	std::cout << "Wrong animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	this->name = std::string(animal.getName());
	this->type = std::string(animal.getType());
	std::cout << "Wrong animal copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name, std::string type) : type(type), name(name)
{
	std::cout << "WrongAnimal Name and Type constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this == &animal) return *this;

	this->name = std::string(animal.getName());
	this->type = std::string(animal.getType());
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getName() const
{
	return this->name;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
