/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:41:36 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/01 11:51:53 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragtrap.hpp"

int main(void) {
    FragTrap test("Test");
    test.attack("Matias");
    test.highFivesGuys();
    return 0;
}