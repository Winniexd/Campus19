/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/03 14:14:30 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

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
    std::cout << "Dog constructor called" << std::endl;
    try {
        this->brain = new Brain;
        if (!this->brain)
            throw malloc_error ("Malloc error");
    }
    catch(const exception& e) {
        std::cout << e.what() << std::endl;
    }
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    try {
        this->brain = new Brain;
        if (!this->brain)
            throw malloc_error ("Malloc error");
    }
    catch(const exception& e) {
        std::cout << e.what() << std::endl;
    }
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}