/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:29:34 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/10 08:39:26 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("Unnamed Weapon") {}

Weapon::Weapon(std::string weapon_name)
{
	this->type = weapon_name;
}

Weapon::~Weapon(void)
{
	std::cout << this->type << " has been destroyed" << std::endl;
}

void Weapon::setType(std::string newType)
{
	this->type = type;
}

static std::string Weapon::getType()
{
	return &(this->type);
}