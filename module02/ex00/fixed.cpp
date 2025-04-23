/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:37 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/21 12:43:48 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << "Self-attribution detected! The objects already have the same address." <<std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    this->_value = raw;
}