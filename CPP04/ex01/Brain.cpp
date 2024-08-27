/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:57:31 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 09:38:33 by jkauker          ###   ########.fr       */
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
		this->ideas[i] = std::string(brain.ideas[i]);
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignment operrator override called" << std::endl;
	if (this == &brain) return *this;

	for (int i = 0; i < 100; ++i)
		this->ideas[i] = std::string(brain.ideas[i]);
	return *this;
}

std::ostream &operator<<(std::ostream &stream, Brain &brain)
{
	(void)brain;
	return (stream << "has some ideas");
}