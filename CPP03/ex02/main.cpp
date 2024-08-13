/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:40:24 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 13:36:15 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "ClapTrap\n" << std::endl;
	{
		ClapTrap hans;
		ClapTrap peter("peter");

		hans.attack("R2D2");
		peter.beRepaired(4);
		peter.takeDamage(10);
		peter.takeDamage(5);
		peter.takeDamage(1);
		hans.beRepaired(1);
	}
	std::cout << "\n\nScavTrap\n" << std::endl;
	{
		ScavTrap a;
		ScavTrap b("lzipp");

		std::cout << "\n" << std::endl;
		a.guardGate();
		a.guardGate();
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		b.takeDamage(10000);
	}
	std::cout << "\n\nFragTrap\n" << std::endl;
	{
		FragTrap a;
		FragTrap b("nsabia");

		std::cout << "\n" << std::endl;
		a.highFiveGuys();
		b.takeDamage(10000);
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
	}
	return (0);
}