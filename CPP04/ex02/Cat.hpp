/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:48:15 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 09:50:13 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string name);
		Cat(const Cat &cat);
		~Cat();
		Cat &operator=(const Cat &cat);
		void makeSound() const;
		std::string getIdea(int idx) const;
};

#endif
