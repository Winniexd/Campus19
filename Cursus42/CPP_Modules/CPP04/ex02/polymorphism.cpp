/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/08 13:39:08 by marvin           ###   ########.fr       */
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

void AAnimal::makeSound() const {

    std::cout << "Grrrrrr" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}

Dog::Dog() : AAnimal("Dog") {
    this->brain = new Brain;
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
    this->brain = new Brain;
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}