/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:20:35 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 09:33:51 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() : _name("ClapTrap"), _hit_points(10), _attack_damage(0), _energy_points(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _attack_damage(0), _energy_points(10)
{
	std::cout << "Default name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	std::cout << "A ClapTrap has been constructed from " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "A ClapTrap has been copy assigned from " << _name << std::endl;

	if (this == &other) return *this;

	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._energy_points;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points <= 0)
	{
		std::cout << "Insufficient energy points to attack " << target << std::endl;
		return;
	}
	_energy_points--;
	std::cout << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << _name << " has no health points anymore! No need to waste energy points on that!" << std::endl;
		return;
	}
	_hit_points -= amount;
	if (_hit_points <= 0)
		std::cout << _name << " died! :c" << std::endl;
	else
		std::cout << _name << " lost " << amount << "hp and is now on " << _hit_points << "hp" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points <= 0)
	{
		std::cout << "Insufficient energy points to repair" <<  std::endl;
		return;
	}
	_hit_points += amount;
	std::cout << _name << "has been repaired to " << _hit_points << "hp" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const ClapTrap &claptrap)
{
	return stream << claptrap; // TODO: check what to do here
}