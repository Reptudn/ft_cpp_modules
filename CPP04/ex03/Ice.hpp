/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:11:17 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 09:39:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#ifndef ICE_HPP
#define ICE_HPP

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);
		void use(ICharacter &target);
		AMateria *clone() const;
};

std::ostream &operator<<(std::ostream &stream, const Ice &ice);

#endif