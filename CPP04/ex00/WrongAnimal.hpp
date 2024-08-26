/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:19:26 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:37:58 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

class WrongAnimal
{
	protected:
		std::string type;
		std::string name;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal(std::string name, std::string type);
		WrongAnimal &operator=(const WrongAnimal &animal);
		void makeSound() const;
		std::string getName() const;
		std::string getType() const;
};

#endif