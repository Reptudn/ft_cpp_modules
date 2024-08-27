/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:53:08 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/27 09:29:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		unsigned int health;
		std::string name;
		AMateria *inv[4];
		AMateria *floor[100];
	public:
		Character();
		Character(const Character &character);
		Character(std::string name);
		Character(std::string name, unsigned int health);
		~Character();
		Character &operator=(const Character &character);
		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

std::ostream &operator<<(std::ostream &stream, const Character &character);

#endif