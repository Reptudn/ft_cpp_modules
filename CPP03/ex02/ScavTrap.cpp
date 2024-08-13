/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:22:18 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 09:35:02 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _isGuarding(false)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _isGuarding(false)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Default ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other), _isGuarding(false)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Default ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment override called" << std::endl;
	if (this == &other) return *this;

	this->_isGuarding = other._isGuarding;
	this->_attack_damage = other._attack_damage;
	this->_energy_points = other._hit_points;
	this->_name = other._name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energy_points <= 0)
	{
		std::cout << _name <<  " has insufficient energy points to attack " << target << std::endl;
		return;
	}
	_energy_points--;
	std::cout << _name << " hits " << target << " and causes " << _attack_damage << " points of damage!" << std::endl;

}

void ScavTrap::guardGate(void)
{
	this->_isGuarding = !this->_isGuarding;

	if (_isGuarding)
		std::cout << "ScavTrap " << _name << " is now in gatekeeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is not in gatekeeper mode anymore" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const ScavTrap &scavtrap)
{
	return stream << scavtrap; // TODO: check what to do here
}