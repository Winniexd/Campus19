/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:17 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/07 14:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP
#include <iostream>
#include "brain.hpp"

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
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        void makeSound(void) const;
};

class Cat: public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        void makeSound(void) const;
};

#endif