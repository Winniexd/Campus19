/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:21:32 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 14:11:20 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool is_signed;
        const int required;
        AForm();
    public:
        AForm(const std::string name, bool is_signed, const int required);
        ~AForm();
        std::string getName() const;
        bool getSigned() const;
        int getRequired() const;
        void beSigned(const Bureaucrat& b);
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif