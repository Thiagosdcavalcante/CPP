/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:41:42 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 16:17:41 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    private:
        int              _value;
        static const int _bits = 8;

    public:    
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
};

void runFixedTests(Fixed &a, Fixed &b, Fixed &c);
Fixed createFixedByValue(Fixed f);
void assignFixedByReference(Fixed& target, const Fixed& source);
Fixed returnFixedByValue();

#endif