/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:37:06 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/19 18:16:06 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main()
{
    Harl h;

    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    h.complain("INVALID");

    return 0;
}