/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:02:19 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 15:03:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
    Weapon weapon = Weapon("crude spiked club");
    
    HumanA bob("Bob", weapon);
    HumanB jim("Jim");
    jim.setWeapon(weapon);
    bob.attack();
    jim.attack();
    weapon.setType("big gun");
    bob.attack();
    jim.attack();
    
    return (0);
}