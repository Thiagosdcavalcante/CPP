/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:48:24 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 17:20:09 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number ) : _fixed( number << this->_fractional )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float number )
	: _fixed( roundf(number * (1 << this->_fractional)) )
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const
{
	return this->_fixed;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(this->getRawBits())
		/ ( 1 << this->_fractional );
}

int		Fixed::toInt( void ) const
{
	return this->_fixed >> this->_fractional;
}

std::ostream&	operator<<( std::ostream & _cout, Fixed const &fixed)
{
	_cout << fixed.toFloat();
	return _cout;
}