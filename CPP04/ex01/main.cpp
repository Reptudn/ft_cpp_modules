/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:51:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 16:51:38 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animal[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50) animal[i] = new Cat();
		else animal[i] = new Dog();
	}
	
	for (int i = 0; i < 100; i++)
	{
		animal[i]->makeSound();
		delete animal[i];
	}

	return 0;
}

