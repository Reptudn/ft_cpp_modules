/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:49:55 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 09:49:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

class PhoneBook
{
	public:
		unsigned int			count;

		PhoneBook();
		~PhoneBook();
		void	Add();
		void	Search();
};

#endif