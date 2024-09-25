/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:12 by mdreesen          #+#    #+#             */
/*   Updated: 2024/07/12 15:04:45 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(25) {
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->getName() << " Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    this->grade = rhs.grade;
    return *this;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

void Bureaucrat::incrementGrade() {
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed form " << f.getName() << std::endl;
    }
    catch(Form::GradeTooLowException& e) {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}