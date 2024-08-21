/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:30 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/21 08:49:25 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef AMATERIA_HPP
#define AMETERIA_HPP

#ifndef ICHARACTER_HPP
# include "ICharacter.hpp"
#endif

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

std::ostream &operator<<(std::ostream &stream, const AMateria &mat);

#endif