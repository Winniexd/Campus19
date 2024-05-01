/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:54:47 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/01 11:34:16 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavtrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hp = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->name << " is in guardkeeping mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << this->name << " attacks " << target << " for " << this->damage << " damage! That's a lot of damage!" << std::endl;
}