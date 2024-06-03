/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:39 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 16:49:48 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int N = 5;
    Zombie *zombies = zombieHorde(N, "Gary");

    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;
    return (0);
}
