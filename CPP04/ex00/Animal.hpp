/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:51 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:33:01 by jkauker          ###   ########.fr       */
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
		virtual ~Animal(); //why virtual? when classes derive from animal and the destructor is not virtual this destructor cannot be called and so might cause leaks
		virtual void makeSound() const;
		std::string getName() const;
		std::string getType() const;
};

#endif