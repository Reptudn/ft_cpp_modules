/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:04:34 by jkauker           #+#    #+#             */
/*   Updated: 2024/07/10 19:26:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	private:
		int 				_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &fixed);
		Fixed &operator=(Fixed const &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
