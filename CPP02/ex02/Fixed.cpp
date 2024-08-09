/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:08:33 by jkauker           #+#    #+#             */
/*   Updated: 2024/08/09 14:34:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 1 << _fractionalBits if _fractionalBits is 8 is equal to 256
// this value is being multiplied to keep the decimal places
// for example 3.5 * 256 = 896
// this can be reverted by simply dividing by 256 again
// this all is basically to store floats as ints with accuracte 3 decimal places whilst the max decimal places is 1 / 256

Fixed::Fixed(float value) : _value(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
	std::cout << "Default float constructor called" << std::endl;
}

Fixed::Fixed(int value) : _value(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
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

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	return stream << fixed.toFloat();
}

Fixed& Fixed::operator=(Fixed const &fixed)
{
	this->_value = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return this->toFloat() < fixed.toFloat();
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return this->toFloat() > fixed.toFloat();
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return this->toFloat() != fixed.toFloat();
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return this->toFloat() == fixed.toFloat();
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return this->toFloat() <= fixed.toFloat();
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return this->toFloat() >= fixed.toFloat();
}

float Fixed::operator+(Fixed other) const
{
	return this->toFloat() + other.toFloat();
}

float	Fixed::operator-(Fixed other) const
{
	return this->toFloat() - other.toFloat();
}

float	Fixed::operator*(Fixed other) const
{
	return this->toFloat() * other.toFloat();
}

float	Fixed::operator/(Fixed other) const
{
	return this->toFloat() / other.toFloat();
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value = static_cast<int>(roundf((this->toFloat() + 1.0) * (1 << _fractionalBits)));
	return temp;
}

Fixed Fixed::operator++()
{
	this->_value = static_cast<int>(roundf((this->toFloat() + 1.0) * (1 << _fractionalBits)));
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value = static_cast<int>(roundf((this->toFloat() - 1.0)* (1 << _fractionalBits)));
	return temp;
}

Fixed Fixed::operator--()
{
	this->_value = static_cast<int>(roundf((this->toFloat() - 1.0) * (1 << _fractionalBits)));
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}
