/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:27:54 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 15:25:21 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavtrap.hpp"

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

ClapTrap::ClapTrap(ClapTrap& c) {
	*this = c;
	std::cout << "Claptrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& c) {
	std::cout << "Claptrap copy assignment operator called" << std::endl;
	this->name = c.name;
	this->hp = c.hp;
	this->energy = c.energy;
	this->damage = c.damage;
	return *this;
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