/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:20:46 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 12:00:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap hans;
	ClapTrap peter("peter");

	hans.attack("R2D2");
	peter.beRepaired(4);
	peter.takeDamage(10);
	peter.takeDamage(5);
	peter.takeDamage(1);
	hans.beRepaired(1);
	return (0);
}