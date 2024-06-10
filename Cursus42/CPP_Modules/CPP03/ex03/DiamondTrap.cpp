/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:35:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/31 17:35:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    this->hp = 100;
    this->energy = 50;
    this->damage = 30;

    std::cout << this->name << " DiamondTrap constructed" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << this->name << " DiamondTrap destructed" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << " || ClapTrap name: " << ClapTrap::name << std::endl;
}