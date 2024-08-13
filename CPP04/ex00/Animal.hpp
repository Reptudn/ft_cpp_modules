/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:51 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 14:59:51 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
		std::string name;
	public:
		Animal();
		Animal(std::string name, std::string type);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &animal);
		~Animal();
		void makeSound();
		std::string getName() const;
		std::string getType() const;
};

std::ostream &operator<<(std::ostream &stream, const Animal &animal);

#endif