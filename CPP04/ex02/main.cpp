/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:51:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/14 10:14:53 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// TODO: check if this leaks

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	// this doesnt work because ts abstract:
	// const Animal* no = new Animal();

	delete j;
	delete i;
	
	return 0;
}

