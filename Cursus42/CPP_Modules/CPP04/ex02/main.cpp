/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:50:37 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/08 13:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"
#include "wrongAnimal.hpp"

int main(void) {

    const AAnimal *dogs[10];
    const AAnimal *cats[10];

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