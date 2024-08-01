/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:28:59 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:57:22 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"

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

Dog::Dog(const Dog& src) : Animal(src), brain(nullptr) {
    try {
        if (src.brain) {
            this->brain = new Brain(*src.brain);
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Dog copy constructor allocation failed: " << e.what() << std::endl;
    }
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
	this->Animal::operator=(src);
    try {
    this->brain = new Brain(*src.brain);
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Dog allocation failed: " << e.what() << std::endl;
    }
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}
