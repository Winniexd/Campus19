/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:27:54 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/31 17:40:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    this->name = name;
    this->hp = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << "ClapTrap constructor called" << std::endl;       
}

ClapTrap::~ClapTrap() {
    std::cout << "Claptrap destructor called" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hp <= 0) {
        std::cout << this->name << " is already dead :(" << std::endl;
        return ;
    }
    std::cout << this->name << " took " << amount << " damage!" << std::endl;
    this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy <= 0) {
        std::cout << this->name << " is out of energy!" << std::endl;
        return ;
    }
    std::cout << this->name << " recovered " << amount << " health!" << std::endl;
    this->hp += amount;
    this->energy -= 1;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energy <= 0) {
        std::cout << this->name << " is out of energy!" << std::endl;
        return ;
    }
    std::cout << "Claptrap " << this->name << " attacks " << target << " for " << this->damage << " damage!" << std::endl;
    this->energy -= 1;
}