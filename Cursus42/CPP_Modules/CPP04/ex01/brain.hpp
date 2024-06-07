<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:06:21 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 14:06:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "polymorphism.hpp"

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
};

=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:57:15 by mdreesen          #+#    #+#             */
/*   Updated: 2024/05/03 14:02:41 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
};

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

>>>>>>> 9aa464e345c4331e245821e72bde2a1ffa3ec5ec
#endif