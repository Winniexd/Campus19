/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:07:12 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 14:58:43 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
    private:
        Weapon *weapon;
        std::string name;
    public:
        void attack(void);
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
};