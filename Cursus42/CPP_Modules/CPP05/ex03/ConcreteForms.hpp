/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConcreteForms.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:05:01 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 15:38:28 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCRETEFORMS_HPP
#define CONCRETEFORMS_HPP
#include "Form.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm: public AForm {
    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat &b) const;
};

class RobotomyRequestForm: public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        void execute(const Bureaucrat &b) const;
};

class PresidentialPardonForm: public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat &b) const;
};

#endif