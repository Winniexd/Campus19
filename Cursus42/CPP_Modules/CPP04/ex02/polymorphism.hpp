/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:17 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/01 13:01:37 by mdreesen         ###   ########.fr       */
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
        virtual AAnimal& operator=(const AAnimal& a);
        AAnimal(const AAnimal& a);
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
        Dog& operator=(const Dog& src);
        Dog(const Dog& rhs);
};

class Cat: public AAnimal {
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