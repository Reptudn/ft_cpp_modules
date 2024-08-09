/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:09:00 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/09 11:00:58 by jkauker          ###   ########.fr       */
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
		Fixed(const int);
		Fixed(const float);
		
		Fixed&	operator=(Fixed const &fixed);

		bool	operator<(const Fixed &fixed) const;
		bool	operator>(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;

		Fixed&	operator+(const Fixed &other) const;
		Fixed&	operator-(const Fixed &other) const;
		Fixed&	operator*(const Fixed &other) const;
		Fixed&	operator/(const Fixed &other) const;

		Fixed&	operator++(int); //post increment
		Fixed&	operator++(); // pre increment
		Fixed&	operator--(int); //post decrement
		Fixed&	operator--(); // pre decrement
		
		friend	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	min(Fixed& a, Fixed& b);
		Fixed&	max(Fixed& a, Fixed& b);
		Fixed&	min(const Fixed& a, const Fixed& b);
		Fixed&	max(const Fixed& a, const Fixed& b);
};

#endif