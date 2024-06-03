/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:40 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 13:49:00 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixed(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float fl) : fixed(roundf(fl * (1 << bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int i) : fixed(i << bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed = f.getRawBits();
    return *this;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << bits);
}

int Fixed::toInt(void) const {
    return this->fixed >> bits;
}

Fixed::Fixed(const Fixed &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

int Fixed::getRawBits(void) const {
    return this->fixed;
}

void Fixed::setRawBits(int const raw) {
    this->fixed = raw;
}

std::ostream& operator<<(std::ostream &out, Fixed const &f) {
    out << f.toFloat();
    return out;
}
