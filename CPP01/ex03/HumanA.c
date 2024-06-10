/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:46:39 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/10 08:51:36 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

HumanA::HumanA() : name("Fred")
{
	this->weapon = Weapon("P-06");
}

HumanA::HumanA(std::string name)
{
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << this->name << " died." << std::cout;
}

HumanA::attack()
{
	std::cout << this->name << " attack with their " + this->weapon.getType() << std::endl;
}