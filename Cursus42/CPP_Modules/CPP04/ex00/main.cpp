/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:50:37 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/07 16:05:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polymorphism.hpp"
#include "wrongAnimal.hpp"

int main(void) {

    std::cout << "__________Right_animals__________" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << meta->getType() << std::endl;
    
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    
    delete j;
    delete i;
    delete meta;
    std::cout << "__________Wrong_animals__________" << std::endl;
    
    const WrongAnimal* wrongd = new WrongDog();
    const WrongAnimal* wrongc = new WrongCat();
    const WrongAnimal* wrong = new WrongAnimal();
    
    std::cout << wrong->getType() << std::endl;
    std::cout << wrongc->getType() << std::endl;
    std::cout << wrongd->getType() << std::endl;
    
    wrong->makeSound();
    wrongc->makeSound();
    wrongd->makeSound();
    
    delete wrong;
    delete wrongc;
    delete wrongd;
    
    return 0;
}