/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:40 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/27 16:24:35 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(void) : f(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float fl) : f(std::roundf(fl * (1 << bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int i) : f(i << bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

float Fixed::toFloat(void) const {
    return static_cast<float>((this->getRawBits()) / (1 << bits));
}

int Fixed::toInt(void) const {
    return this->f >> bits;
}

Fixed::Fixed(const Fixed &f) {
    std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->f;
}

void Fixed::setRawBits(int const raw) {
    this->f = raw;
}

std::ostream& operator<<(std::ostream &out, Fixed const &f) {
    out << f.toFloat();
    return out;
}