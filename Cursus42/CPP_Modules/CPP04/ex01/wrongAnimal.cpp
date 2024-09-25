/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:17 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 14:44:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("bob") {
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    this->type = type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = a;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type = a.type;
    return *this;
}

void WrongAnimal::makeSound() const {

    std::cout << "Grrrrrr" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
    std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
