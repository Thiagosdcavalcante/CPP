/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:44:57 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 19:12:46 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed createFixedByValue(Fixed f)
{
    std::cout << "Function createFixedByValue called." << std::endl;
    return (f);
}

void assignFixedByReference(Fixed& target, const Fixed& source)
{
    target = source;
    std::cout << "Inside function: assignment made." << std::endl;
}

Fixed returnFixedByValue()
{
    Fixed temp;
    temp.setRawBits(100);
    std::cout << "Function returnFixedByValue called." << std::endl;
    return (temp);
}

void runFixedTests(Fixed &a, Fixed &b, Fixed &c)
{
    std::cout << "\n=== Test 2: Self-attribution ===" << std::endl;
    Fixed *ptr = &a;
    a = *ptr;

    std::cout << "\n=== Test 3: Assignment chaining ===" << std::endl;
    a.setRawBits(42);
    Fixed d;
    Fixed e;
    d = e = a;
    std::cout << "d: " << d.getRawBits() << std::endl;
    std::cout << "e: " << e.getRawBits() << std::endl;

    std::cout << "\n=== Test 4: Passing by Value to Function ===" << std::endl;
    Fixed f = createFixedByValue(a);
    std::cout << "f: " << f.getRawBits() << std::endl;

    std::cout << "\n=== Test 5: Passing by Reference to Function ===" << std::endl;
    assignFixedByReference(b, c);
    std::cout << "b after assignment via function: " << b.getRawBits() << std::endl;

    std::cout << "\n=== Test 6: Return by Function Value ===" << std::endl;
    Fixed g = returnFixedByValue();
    std::cout << "g: " << g.getRawBits() << std::endl;

    std::cout << "\n=== Test 7: Use with Constant Objects ===" << std::endl;
    const Fixed constFixedOne = a;
    const Fixed constFixedTwo;
    std::cout << "constFixedOne: " << constFixedOne.getRawBits() << std::endl;
    std::cout << "constFixedTwo: " << constFixedTwo.getRawBits() << std::endl;
}