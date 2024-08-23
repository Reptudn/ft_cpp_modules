/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:21:20 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 16:58:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() :  health(20)
{
	this->name = "Wanderer";
	std::cout << "Default character constructor called" << std::endl;
}

Character::Character(std::string name) : health(20)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;
	for (int i = 0; i < 100; i++)
		this->floor[i] = nullptr;
	std::cout << "Name Character constructor called" << std::endl;
}

Character::Character(std::string name, unsigned int health) : health(health)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inv[i] = nullptr;
	for (int i = 0; i < 100; i++)
		this->floor[i] = nullptr;
	std::cout << "Name and Health Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inv[i] != nullptr) delete inv[i];
	for (int i = 0; i < 100; i++)
		if (this->floor[i] != nullptr) delete this->floor[i];
}

Character::Character(const Character &character)
{
	this->health = character.health;
	for (int i = 0; i < 4; i++)
	{
		if (character.inv[i])
			this->inv[i] = character.inv[i]->clone();
		else this->inv[i] = nullptr;
	}
	for (int i = 0; i < 100; i++)
	{
		if (character.floor[i])
			this->floor[i] = character.floor[i]->clone();
		else this->floor[i] = nullptr;
	}
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
	{
		if (inv[i] == m)
		{
			std::cout << m->getType() << " already in inv." << std::endl;
			return;
		}
		if (inv[i] == nullptr)
		{
			inv[i] = m;
			std::cout << "(Character) Added " + m->getType() + " at " << i << std::endl; 
			return;
		}
	}
	std::cout << "Inventory already full. Deleting it." << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	
	if (idx < 0 || idx > 3)
	{
		std::cout << "No slot available at such pos (0-3 allowed): " << idx << std::endl;
		return;
	}
	if (inv[idx] == nullptr)
		std::cout << "No item at slot " << idx << std::endl;
	else
	{
		std::cout << "Dropping item " << inv[idx]->getType() << " at slot " << idx << std::endl;
		for (int i = 0; i < 100; i++)
		{
			if (floor[i] == nullptr)
			{
				floor[i] = inv[idx];
				std::cout << inv[idx]->getType() << " is now on the floor next to the " + getName() << std::endl;
				inv[idx] = nullptr;
				return;
			}
		}
		std::cout << "There is no space on the floor. Item will be deleted!" << std::endl;
		delete inv[idx]; // yes yes i dont think anyone will drop 100 items so imma just delete this here if its more
		inv[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4) return;
	if (this->inv[idx] == nullptr)
		std::cout << "No item at slot " << idx << std::endl;
	else
	{
		this->inv[idx]->use(target);
		std::cout << this->getName() << " used " << inv[idx]->getType() << " at " << target.getName() << std::endl;
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
		if (character.inv[i])
			this->inv[i] = character.inv[i]->clone();
		else this->inv[i] = nullptr;
	}
	for (int i = 0; i < 100; i++)
	{
		if (character.floor[i])
			this->floor[i] = character.floor[i]->clone();
		else this->floor[i] = nullptr;
	}
	std::cout << "Character assignment override called" << std::endl;
	return *this;
}