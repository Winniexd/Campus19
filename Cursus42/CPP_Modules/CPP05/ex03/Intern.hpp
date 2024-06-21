/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:37:39 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 15:57:51 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "ConcreteForms.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
};

#endif