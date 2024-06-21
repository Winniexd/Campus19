/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:26:15 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 13:17:29 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("DefaultForm"), is_signed(false), required(0) {
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string name, bool is_signed, const int required) : name(name), is_signed(is_signed), required(required) {
    if (required < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (required > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << name << " Form constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Default Form destructor called" << std::endl;
}

std::string Form::getName() const {
    return this->name;
}

bool Form::getSigned() const {
    return this->is_signed;
}

int Form::getRequired() const {
    return this->required;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->required)
        throw GradeTooLowException();
    this->is_signed = true;
}

const char* Form::GradeTooLowException::what() const throw() {
    return "the grade is lower than required!";
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "Form name: " << f.getName() << ", signed?: " << f.getSigned() << ", required grade: " << f.getRequired();
    return out;
}