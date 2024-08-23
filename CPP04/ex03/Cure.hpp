/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:11:17 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 13:52:30 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &Cure);
		Cure &operator=(const Cure &Cure);
		void use(ICharacter &target);
		AMateria *clone() const;
};

std::ostream &operator<<(std::ostream &stream, const Cure &Cure);

#endif