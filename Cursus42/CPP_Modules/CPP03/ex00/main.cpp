/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:36:50 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/30 13:15:32 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"

int main(void) {
    ClapTrap test("Claptrap1");

    test.attack("stupid fly");
    test.takeDamage(2);
}