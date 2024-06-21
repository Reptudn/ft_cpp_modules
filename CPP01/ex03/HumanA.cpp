/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:46:39 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/21 12:44:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " spawned with a " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " + this->_weapon.getType() << std::endl;
}