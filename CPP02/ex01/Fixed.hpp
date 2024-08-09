/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:09:00 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/09 15:45:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(Fixed const &old);
		Fixed &operator=(Fixed const &fixed);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
		float	toFloat(void) const;
		int		toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif