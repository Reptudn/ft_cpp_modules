/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:20:41 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/13 09:29:26 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <ostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_attack_damage;
		int			_energy_points;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &stream, const ClapTrap &claptrap);

#endif