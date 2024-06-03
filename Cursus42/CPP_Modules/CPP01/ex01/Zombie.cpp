/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:12:22 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 16:48:26 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie(void) {
    std::cout << name << " has been killed" << std::endl;
}

void Zombie::announce(void) {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::giveName(std::string name) {
    this->name = name;
}
