/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:50:37 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:53 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"
#include "wrongAnimal.hpp"

int main(void) {

    const Animal *dogs[10];
    const Animal *cats[10];

    Cat basic;
    {
        Cat tmp = basic;
    }

    std::cout << "__________DOGS__________" << std::endl;
    for (int i = 0; i < 10; i++) {
        dogs[i] = new Dog();
    }
    std::cout << std::endl;

    std::cout << "__________CATS__________" << std::endl;
    for (int i = 0; i < 10; i++) {
        cats[i] = new Cat();
    }
    std::cout << std::endl;
    
    std::cout << "__________DELETE_DOGS__________" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete dogs[i];
    }
    std::cout << std::endl;
    
    std::cout << "__________DELETE_CATS__________" << std::endl;
    for (int i = 0; i < 10; i++) {
        delete cats[i];
    }
    
    return 0;
}