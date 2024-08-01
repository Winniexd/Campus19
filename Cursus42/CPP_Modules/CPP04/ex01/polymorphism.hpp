/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:17 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 12:55:50 by mdreesen         ###   ########.fr       */
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
        virtual Animal& operator=(const Animal& a);
        Animal(const Animal& a);
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
        Dog& operator=(const Dog& src);
        Dog(const Dog& rhs);
};

class Cat: public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        void makeSound(void) const;
        Cat& operator=(const Cat& src);
        Cat(const Cat& rhs);
};

#endif