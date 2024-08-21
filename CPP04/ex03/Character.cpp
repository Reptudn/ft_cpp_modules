/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:21:20 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/21 08:47:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character() : ICharacter("Wanderer"), health(20)
{
	std::cout << "Default character constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter(name), health(20)
{
	std::cout << "Name Character constructor called" << std::endl;
}

Character::Character(std::string name, unsigned int health) : ICharacter(name), health(health)
{
	std::cout << "Name and Health Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	delete [] static_cast<AMateria**>(inv); // XXX: dont know about this one
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
		std::cout << this << " used " << inv[idx] << " at " << target.getName() << std::endl;
		unequip(idx);
	}
}

std::ostream &operator<<(std::ostream &stream, const Character &character)
{
	return (stream << character.getName());
}