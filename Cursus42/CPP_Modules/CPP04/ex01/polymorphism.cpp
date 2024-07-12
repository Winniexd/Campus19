/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:06:09 by mdreesen          #+#    #+#             */
/*   Updated: 2024/07/12 14:07:41 by mdreesen         ###   ########.fr       */
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

Dog::Dog() : Animal("Dog") {
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

Cat::Cat() : Animal("Cat") {
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