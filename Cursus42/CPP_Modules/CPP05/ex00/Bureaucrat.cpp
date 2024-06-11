/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:12 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/11 16:39:40 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->grade = grade;
    std::cout << this->getName() << " constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat default destructor called" << std::endl;
}

int Bureaucrat::getGrade() {
    return this->grade;
}

std::string Bureaucrat::getName() {
    return this->name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}