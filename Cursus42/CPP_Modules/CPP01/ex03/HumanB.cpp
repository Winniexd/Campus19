/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:18:20 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:53 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack(void) {
    if (this->weapon && !this->weapon->getType().empty())
        std::cout << name << " attacks with a " << this->weapon->getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}