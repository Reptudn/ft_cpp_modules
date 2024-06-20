/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:25:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/06/20 12:54:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
	private:
		std::string type;
	public:
		std::string getType() const;
		void setType(std::string newType);
		Weapon(std::string weapon);
		Weapon();
		~Weapon();
};

#endif