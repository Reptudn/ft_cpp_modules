/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:46:39 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/20 13:02:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() : name("Fred")
{
	this->weapon = Weapon("P-06");
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{
	std::cout << this->name << " died." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attack with their " + this->weapon.getType() << std::endl;
}