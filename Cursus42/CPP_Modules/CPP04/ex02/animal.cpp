/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:31:08 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"

AAnimal::AAnimal() : type("bob") {
    std::cout << "Default animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) {
    this->type = type;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

AAnimal& AAnimal::operator=(const AAnimal& a) {
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = a.type;
    return *this;
}

void AAnimal::makeSound() const {

    std::cout << "Grrrrrr" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
