/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:40:22 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/31 17:32:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragtrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hp = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << this->name << " gives you a high five!" << std::endl;
}

