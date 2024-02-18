/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:47 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 14:45:56 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

void HumanA::attack(void) {
    if (!this->weapon.getType().empty())
        std::cout << name << " attacks with a " << this->weapon.getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon" << std::endl;
}