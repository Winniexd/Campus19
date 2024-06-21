/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:25 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 15:32:19 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ConcreteForms.hpp"

int main() {
    Bureaucrat b = Bureaucrat("Apple", 11);
    Bureaucrat c = Bureaucrat();
    ShrubberyCreationForm f = ShrubberyCreationForm("Park");
    RobotomyRequestForm r = RobotomyRequestForm("eh");
    PresidentialPardonForm p = PresidentialPardonForm("Matias");
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << f << std::endl;
    b.signForm(p);
    b.executeForm(p);
    return 0;
}