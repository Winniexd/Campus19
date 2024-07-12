/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/07/12 14:45:29 by mdreesen         ###   ########.fr       */
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

Dog::Dog() : AAnimal("Dog") {
    try {
    this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Dog allocation failed: " << e.what() << std::endl;
    }
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

Cat::Cat() : AAnimal("Cat") {
    try {
    this->brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Cat allocation failed: " << e.what() << std::endl;
    }
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}