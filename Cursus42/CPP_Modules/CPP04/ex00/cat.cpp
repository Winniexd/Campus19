/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:25:30 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:40:49 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
