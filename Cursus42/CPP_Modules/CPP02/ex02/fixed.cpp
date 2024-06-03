/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:40 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 17:57:20 by mdreesen         ###   ########.fr       */
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

Fixed Fixed::operator+(const Fixed &f) {
    return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) {
    return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) {
    return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) {
    return Fixed(this->toFloat() / f.toFloat());
}

bool Fixed::operator>(const Fixed &f) {
    return this->fixed > f.fixed;
}

bool Fixed::operator<(const Fixed &f) {
    return this->fixed > f.fixed;
}

bool Fixed::operator>=(const Fixed &f) {
    return this->fixed >= f.fixed;
}

bool Fixed::operator<=(const Fixed &f) {
    return this->fixed <= f.fixed;
}

bool Fixed::operator==(const Fixed &f) {
    return this->fixed <= f.fixed;
}

bool Fixed::operator!=(const Fixed &f) {
    return this->fixed <= f.fixed;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::operator++() {
    ++(this->fixed);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    tmp.fixed = (this->fixed)++;
    return tmp;
}

Fixed& Fixed::operator--() {
    --(this->fixed);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    tmp.fixed = (this->fixed)--;
    return tmp;
}
