/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:31 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 14:43:15 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->setType(type);
}

std::string &Weapon::getType(void) {
    return (this->type);
}

void Weapon::setType(std::string type) {
    this->type = type;
}