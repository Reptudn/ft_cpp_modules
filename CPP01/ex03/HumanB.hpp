/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:42:42 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/10 08:46:30 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon weapon;
		std::string name;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon weapon);
};

#endif