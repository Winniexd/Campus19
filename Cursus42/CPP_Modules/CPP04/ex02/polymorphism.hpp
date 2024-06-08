/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:17 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/08 13:38:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP
#include <iostream>
#include "brain.hpp"

class AAnimal {
    protected:
        std::string type;
    public:
        std::string getType() const;
        AAnimal(std::string type);
        AAnimal();
        virtual ~AAnimal();
        virtual void makeSound(void) const = 0;
};

class Dog: public AAnimal {
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        void makeSound(void) const;
};

class Cat: public AAnimal {
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        void makeSound(void) const;
};

#endif