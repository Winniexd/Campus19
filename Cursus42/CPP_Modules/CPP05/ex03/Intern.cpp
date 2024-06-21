/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:37:34 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 16:03:12 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Default Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string form, std::string target) {
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (int i = 0; i < 3; i++) {
        if (form == formNames[i]) {
            std::cout << "Intern created " << formNames[i] << std::endl;
            return forms[i];   
        }
    }
    std::cout << "Intern couldn't create " << form << std::endl;
    return NULL;
}