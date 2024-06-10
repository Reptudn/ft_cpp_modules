/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:25:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/10 08:35:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		std::string getType() const;
		void setString(std::string newType);
		Weapon(std::string weapon);
		Weapon();
		~Weapon();
};

#endif