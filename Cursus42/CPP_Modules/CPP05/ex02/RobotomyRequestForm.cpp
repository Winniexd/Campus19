/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:02:19 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 15:25:19 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcreteForms.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72), target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const {
    if (this->getSigned() && b.getGrade() <= 45) {
        std::srand(std::time(NULL));
        if (std::rand() % 2) {
            std::cout << target << " has been successfully robotomized" << std::endl;
            return ;
        }
        std::cout << "Robotomy has failed" << std::endl;
    }
}