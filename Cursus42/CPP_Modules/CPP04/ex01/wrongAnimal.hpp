/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:40:36 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 14:40:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        std::string getType() const;
        WrongAnimal(std::string type);
        WrongAnimal();
        ~WrongAnimal();
        void makeSound(void) const;
};

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        void makeSound(void) const;
};

class WrongDog: public WrongAnimal {
    public:
        WrongDog();
        ~WrongDog();
        void makeSound(void) const;
};

#endif