/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:28:11 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 15:33:39 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcreteForms.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25), target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    if (this->getSigned() && b.getGrade() <= 5) {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        return ;
    }
    std::cout << "I don't owe you an apology!!" << std::endl;
}