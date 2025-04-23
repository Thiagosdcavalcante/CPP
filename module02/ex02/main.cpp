/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:00:56 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/23 16:48:06 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "|===> Test 1: Initial values ​​for a and b <===|\n";
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "|===> Test 2: Increment and Decrement <===|\n";
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after ++a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after a++: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a after --a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a after a--: " << a << std::endl;

    std::cout << "\n===> Test 3: Arithmetic Operations <===\n";
    Fixed c(3.5f);
    Fixed d(2.5f);
    
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << "|===> Test 4: Comparisons <===|\n";
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    std::cout << "|===> Test 4: Min e Max <===|\n";
    std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "Min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "Max(c, d): " << Fixed::max(c, d) << std::endl;

    return (0);
}