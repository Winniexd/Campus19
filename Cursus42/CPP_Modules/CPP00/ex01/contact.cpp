/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:12:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 12:51:59 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string Contact::GetInfo(std::string str) {

    std::string input = "";
    bool valid = false;
    while (!valid) {
        std::cout << str;
        std::getline(std::cin, input);
        if (!input.empty() && std::cin.good())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Input is invalid, please try again!" << std::endl;
        }
    }
    return (input);
}

void Contact::Add(int i) {
    std::cin.ignore();
    this->FirstName = this->GetInfo("Please enter your first name: ");
    this->LastName = this->GetInfo("Please enter your last name: ");
    this->NickName = this->GetInfo("Please enter your nickname: ");
    this->PhoneNumber = this->GetInfo("Please enter your phone number: ");
    this->DarkestSecret = this->GetInfo("What is your darkest secret? 👀 ");
    this->index = i % 8;
}

std::string Contact::PrintLen(std::string str) {
    if (str.length() > 10)
        str = str.substr(0, 9) + '.';
    return str;
}

void Contact::Display(void) {
    if (!FirstName.empty() || !LastName.empty() || !NickName.empty()) {
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << PrintLen(FirstName);
    std::cout << "|" << std::setw(10) << PrintLen(LastName);
    std::cout << "|" << std::setw(10) << PrintLen(NickName);
    std::cout << "|" << std::endl;
    }
}

void Contact::View(void) {
    if (!FirstName.empty() || !LastName.empty() || !NickName.empty()) {
        std::cout << FirstName << std::endl;
        std::cout << LastName << std::endl;
        std::cout << NickName << std::endl;
        std::cout << PhoneNumber << std::endl;
		std::cout << DarkestSecret << std::endl;
	}
}