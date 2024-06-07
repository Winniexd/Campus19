/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/07 14:34:09 by marvin           ###   ########.fr       */
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

void Animal::makeSound() const {

    std::cout << "Grrrrrr" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

Dog::Dog() : Animal("Dog") {
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

Cat::Cat() : Animal("Cat") {
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