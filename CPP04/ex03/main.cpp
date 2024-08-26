/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:49:09 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/26 14:21:12 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

int main()
{
	{
		
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->equip(tmp);
		me->equip(new Ice());
		me->equip(tmp->clone());
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(6);
		me->unequip(0);
		me->use(0, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n\n" << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		Character *lol = new Character("pog");
		
		lol->equip(src->createMateria("ice"));
		lol->equip(src->createMateria("ice"));
		lol->equip(src->createMateria("cure"));
		lol->equip(src->createMateria("ice"));
		
		Character &lol_ref = *lol;
		Character *pog = new Character(lol_ref);

		pog->use(0, lol_ref);
		pog->use(1, lol_ref);
		pog->use(2, lol_ref);
		pog->use(3, lol_ref);
	}

	return 0;
}

