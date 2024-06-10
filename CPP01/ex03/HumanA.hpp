/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:42:42 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/10 08:45:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon weapon;
		std::string name;
	public:
		HumanA();
		HumanA(std::string name);
		~HumanA();
		void attack();
};

#endif