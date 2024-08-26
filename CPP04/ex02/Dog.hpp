/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:48:15 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:52:30 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string name);
		Dog(const Dog &dog);
		~Dog();
		Dog &operator=(const Dog &dog);
		void makeSound() const;
		std::string getIdea(int idx) const;
};

#endif
