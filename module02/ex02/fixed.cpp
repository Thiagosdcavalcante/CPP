/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:56:36 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 16:48:49 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << "Self-attribution detected! The objects already have the same value." <<std::endl;
    return (*this);
}

Fixed::Fixed(const int intValue)
{
    _value = intValue << _bits;
}
Fixed::Fixed(const float floatValue)
{
    _value = roundf(floatValue * 256);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_bits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed & other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(_value + other._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(_value - other._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
  
    result.setRawBits((_value * other._value) >> _bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        std::cout << "Error: division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((_value << _bits) / other._value);
    return (result);
}

Fixed& Fixed::operator++()
{
    _value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()
{
    _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed::~Fixed()
{
    return ;
}