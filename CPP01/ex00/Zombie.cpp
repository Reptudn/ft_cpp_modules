/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:52:17 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/21 10:56:36 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie::Zombie()
{
	this->name = "Random";
	std::cout << this->name << " has awaken from the dead!" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << " has awaken from the dead!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " died a second time" << std::endl;	
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
