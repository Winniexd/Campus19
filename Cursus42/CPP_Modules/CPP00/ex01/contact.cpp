/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:12:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/17 17:38:11 by mdreesen         ###   ########.fr       */
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

void Contact::Init(int i) {
    std::cin.ignore();
    this->FirstName = this->GetInfo("Please enter your first name: ");
    this->LastName = this->GetInfo("Please enter your last name: ");
    this->NickName = this->GetInfo("Please enter your nickname: ");
    this->PhoneNumber = this->GetInfo("Please enter your phone number: ");
    this->DarkestSecret = this->GetInfo("What is your darkest secret? 👀 ");
    this->index = i % 8;
}