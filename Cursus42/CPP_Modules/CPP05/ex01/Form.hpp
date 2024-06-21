/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:21:32 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 13:03:07 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool is_signed;
        const int required;
        Form();
    public:
        Form(const std::string name, bool is_signed, const int required);
        ~Form();
        std::string getName() const;
        bool getSigned() const;
        int getRequired() const;
        void beSigned(const Bureaucrat& b);
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif