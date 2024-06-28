/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:35:24 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 15:26:56 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>

class ClapTrap {
    protected :
        std::string name;
        int hp;
        int energy;
        int damage;
    public :
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap(std::string name);
        ~ClapTrap();
		ClapTrap(ClapTrap& c);
		ClapTrap& operator=(ClapTrap& c);
};

class FragTrap: public ClapTrap {
    public :
        FragTrap(std::string name);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif