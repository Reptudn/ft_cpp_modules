/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:29 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/04 14:50:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	int amount = 10;

	zombieHorde(amount, "Zombie");
	for (int i = 0; i < amount; i++)
	{
		zombieHorde(amount, "Zombie")[i].announce();
		delete &zombieHorde(amount, "Zombie")[i]; // TODO: check if this is correct
	}
	
	return 0;
}