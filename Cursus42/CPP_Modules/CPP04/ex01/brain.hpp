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

#endif