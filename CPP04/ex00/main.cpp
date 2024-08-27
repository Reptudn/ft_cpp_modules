/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:51:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 11:22:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();

	const WrongAnimal *wanimal = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();

	wanimal->makeSound();
	wcat->makeSound();

	const Dog &dog2 = Dog("Pete");
	const Dog dog3 = Dog(dog2);

	delete meta;
	delete cat;
	delete dog;
	delete wanimal;
	delete wcat;

	return 0;
}