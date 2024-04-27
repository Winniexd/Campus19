/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:40 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/27 14:37:23 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed() {
    this->f = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::Fixed(Fixed &f) {
    std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->f;
}

void Fixed::setRawBits(int const raw) {
    this->f = raw;
}
