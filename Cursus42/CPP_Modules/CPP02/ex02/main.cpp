/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:08:22 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 17:58:11 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void) {
    Fixed a(Fixed(15.317f) - Fixed(2.302f));
    Fixed b(Fixed(1.0012f) + Fixed(5.451f));
    bool c = Fixed(15.232f) > Fixed(6.123f);
    bool d = Fixed(12.32f) > Fixed(15.12f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "max between a and b is " << Fixed::max(a, b) << std::endl;
    std::cout << "min between a and b is " << Fixed::min(a, b) << std::endl;
    std::cout << ++a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a-- << std::endl;
    return 0;
}