/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:39 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 13:37:28 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie zomb("Foo");
    zomb.announce();

    randomChump("Bob");
    Zombie *zomb3 = newZombie("Gary");
    zomb3->announce();
    delete(zomb3);
}