/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:29:18 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"

Animal::Animal() : type("bob") {
    std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string type) {
    this->type = type;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& a) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal& Animal::operator=(const Animal& a) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = a.type;
    return *this;
}

void Animal::makeSound() const {

    std::cout << "Grrrrrr" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
