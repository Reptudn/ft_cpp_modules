/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:53:05 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 09:35:33 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment override called" << std::endl;
	if (this == &other) return *this;

	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	
	return *this;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << _name << " says high-five" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const FragTrap &fragtrap)
{
	return stream << fragtrap; // TODO: check what to do here
}