/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:28:19 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 13:00:07 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"

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

Cat::Cat(const Cat& src) : AAnimal(src), brain(nullptr) {
    try {
        if (src.brain) {
            this->brain = new Brain(*src.brain);
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Cat copy constructor allocation failed: " << e.what() << std::endl;
    }
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	this->AAnimal::operator=(src);
    try {
    this->brain = new Brain(*src.brain);
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Cat allocation failed: " << e.what() << std::endl;
    }
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}
