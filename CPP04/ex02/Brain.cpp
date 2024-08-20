/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:57:31 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/20 13:46:10 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "random idea";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignment operrator override called" << std::endl;
	if (this == &brain) return *this;

	for (int i = 0; i < 100; ++i)
		this->ideas[i] = brain.ideas[i];
	return *this;
}

std::ostream &operator<<(std::ostream &stream, Brain &brain)
{
	return (stream << "has some ideas");
}