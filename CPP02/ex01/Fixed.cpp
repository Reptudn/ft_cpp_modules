/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:08:33 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/09 08:31:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.cpp"
#include <ostream>

Fixed::Fixed() : _isFloat(false)
{
	this->_isFloat = false;
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
	this->_isFloat = true;
	this->_value = value;
	std::cout << "Default float constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	this->_isFloat = false;
	this->_value = value;
	std::cout << "Default int constructor called" << std::endl;
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->_value) / (1 << this->_fractionalBits);;
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toInt();
	return os;
}