/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:29 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/04 14:42:24 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main ()
{
	Zombie* zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;
	randomChump("Chump");

	return 0;
}