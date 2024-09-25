/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:26:15 by mdreesen          #+#    #+#             */
/*   Updated: 2024/07/12 15:14:58 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

AForm::AForm() : name("DefaultForm"), is_signed(false), required(0) {
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool is_signed, const int required) : name(name), is_signed(is_signed), required(required) {
    if (required < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (required > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << name << " AForm constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "Default AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& src): required(src.required), is_signed(src.is_signed),  name(src.name) {
    *this = src;
}

AForm& AForm::operator=(const AForm& rhs) {
    is_signed = rhs.getSigned();
    return *this;
}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getSigned() const {
    return this->is_signed;
}

int AForm::getRequired() const {
    return this->required;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->required)
        throw GradeTooLowException();
    this->is_signed = true;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "the grade is lower than required!";
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form name: " << f.getName() << ", signed?: " << f.getSigned() << ", required grade: " << f.getRequired();
    return out;
}