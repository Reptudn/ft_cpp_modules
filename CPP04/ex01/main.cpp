/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:51:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 09:16:19 by jkauker          ###   ########.fr       */
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

	std::cout << "\n--------------\n" << std::endl;

	Dog tmp;
	tmp = Dog("Hans");

	Dog tmp2 = Dog(tmp);

	std::string idea0 = tmp.getIdea(0);
	std::string idea2 = tmp2.getIdea(0);

	if (&idea0 == &idea2)
		std::cout << "---> Both got exactly the same idea" << std::endl;
	else
		std::cout << "---> Their ideas are different" << std::endl;

	return 0;
}

