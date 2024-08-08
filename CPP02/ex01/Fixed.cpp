/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:08:33 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/08 19:31:16 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.cpp"

Fixed::Fixed() : _isFloat(false)
{
	_isFloat = false;
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
	_isFloat = true;
	_value = value;
	std::cout << "Default float constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	_isFloat = false;
	_value = value;
	std::cout << "Default int constructor called" << std::endl;
}

float Fixed::toFloat()
{
	if (_isFloat) return _value;
	return _value;
}

int Fixed::toInt()
{
	if (!_isFloat) return _value;
	return _value;
}