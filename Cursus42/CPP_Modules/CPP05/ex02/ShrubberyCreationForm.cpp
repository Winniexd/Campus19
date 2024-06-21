/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:16:44 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 14:57:33 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConcreteForms.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreatonForm", false, 145), target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    if (this->getSigned() && b.getGrade() <= 137) {
        std::string fileName = target + "_shrubbery";
        std::ofstream outFile(fileName.c_str());
        if (!outFile) {
            std::cout << "Error while opening file " << fileName << std::endl;
            return ;
        }
        std::string tree =
        "          &&& &&  & &&\n"
        "      && &\\/&\\|& ()|/ @, &&\n"
        "      &\\/(/&/&||/& /_/)_&/_&\n"
        "   &() &\\/&|()|/&\\/ '%\" & ()\n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "&&   && & &| &| /& & % ()& /&&\n"
        " ()&_---()&\\&\\|&&-&&--%---()~\n"
        "     &&     \\|||\n"
        "             |||\n"
        "             |||\n"
        "             |||\n"
        "       , -=-~  .-^- _\n";
    outFile << tree;
    outFile.close();
    }
}