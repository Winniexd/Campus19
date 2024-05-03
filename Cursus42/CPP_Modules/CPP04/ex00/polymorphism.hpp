/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:17 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/03 12:17:50 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        std::string getType() const;
        Animal(std::string type);
        Animal();
        virtual ~Animal();
        virtual void makeSound(void) const;
};

class Dog: public Animal {
    public:
        Dog();
        ~Dog();
        void makeSound(void) const;
};

class Cat: public Animal {
    public:
        Cat();
        ~Cat();
        void makeSound(void) const;
};

#endif