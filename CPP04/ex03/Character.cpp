/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:21:20 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 14:47:00 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character() :  health(20)
{
	this->name = "Wanderer";
	std::cout << "Default character constructor called" << std::endl;
}

Character::Character(std::string name) :  health(20)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;
	std::cout << "Name Character constructor called" << std::endl;
}

Character::Character(std::string name, unsigned int health) : health(health)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;
	std::cout << "Name and Health Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inv[i] != nullptr) delete inv[i];
}

Character::Character(const Character &character)
{
	this->health = character.health;
	for (int i = 0; i < 4; i++)
		this->inv[i] = character.inv[i]->clone();
	std::cout << "Character copy constructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	if (!m) return;
	for (int i = 0; i < 4; i++)
		if (inv[i] != nullptr) inv[i] = m;
	std::cout << "Inventory already full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4) return;
	if (inv[idx] == nullptr)
		std::cout << "No item at slot " << idx << std::endl;
	else
	{
		std::cout << "Deleted item "<< inv[idx] << " at slot " << idx << std::endl;
		delete inv[idx];
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4) return;
	if (inv[idx] == nullptr)
		std::cout << "No item at slot " << idx << std::endl;
	else
	{
		inv[idx]->use(target);
		std::cout << this << " used " << inv[idx] << " at " << target.getName() << std::endl;
		unequip(idx);
	}
}

std::ostream &operator<<(std::ostream &stream, const Character &character)
{
	return (stream << character.getName());
}

Character &Character::operator=(const Character &character)
{
	this->health = character.health;
	this->name = character.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] != nullptr)
			delete this->inv[i];
		this->inv[i] = character.inv[i]->clone();
	}
	std::cout << "Character assignment override called" << std::endl;
	return *this;
}