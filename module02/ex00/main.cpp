/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:44:25 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 16:03:14 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main( void )
{
    std::cout << "=== Test 1: Construction and Basic Assignment ===" << std::endl;
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    runFixedTests(a, b, c);

    return (0);
}