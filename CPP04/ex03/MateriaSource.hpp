/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:34:07 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/23 14:06:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *mat[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const & type);
};

std::ostream &operator<<(std::ostream &stream, const MateriaSource &src);

#endif