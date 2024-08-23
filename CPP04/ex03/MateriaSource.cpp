/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:46:22 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 15:44:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		mat[i] = nullptr;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (mat[i] != nullptr) delete mat[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "MateriaSource assignment operator overload called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (mat[i] != nullptr)
			delete mat[i];
		if (src.mat[i])
			mat[i] = src.mat[i]->clone();
		else mat[i] = nullptr;
	}
	return *this;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
		return new Ice();
	else if (type == "cure")
		return new Cure();
	else std::cout << "Invalid type to create Materia: " + type << std::endl;
	return nullptr;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (!mat) return;
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] == nullptr)
		{
			this->mat[i] = mat;
			std::cout << "(MateriaSource) Learned " + mat->getType() + " at " << i << std::endl;
			return;
		}
	}
	std::cout << "No slots left to learn anoter Materia. Deleting it." << std::endl;
	delete mat;
}

std::ostream &operator<<(std::ostream &stream, const MateriaSource &src)
{
	(void)src;
	return (stream << "MateriaSource");
}