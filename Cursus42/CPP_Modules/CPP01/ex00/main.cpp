/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:39 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 16:45:31 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie zomb("Larry");
    zomb.announce();

    randomChump("Barry");
    Zombie *zomb3 = newZombie("Gary");
    zomb3->announce();
    delete(zomb3);
}
