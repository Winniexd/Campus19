/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:43 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 14:38:41 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        ~Bureaucrat();
        void incrementGrade();
        void decrementGrade();
        std::string getName() const;
        int getGrade() const;
        void signForm(AForm& f);
        void executeForm(const AForm& form);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &b);

#endif