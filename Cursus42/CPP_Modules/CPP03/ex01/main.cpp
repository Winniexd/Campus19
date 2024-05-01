/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:59:28 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/01 11:33:23 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavtrap.hpp"

int main() {
    ScavTrap test("Test");
    test.attack("Matias");
    test.guardGate();
    return 0;
}