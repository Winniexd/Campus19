/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:13:50 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 13:04:19 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
    amount = 0;
}

void PhoneBook::Start(void) {
    std::cout << "Available Commands" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "ADD: adds contact to the phonebook" << std::endl;
    std::cout << "SEARCH: displays a specific contact" << std::endl;
    std::cout << "EXIT: the program quits and the contacts are lost forever!" << std::endl;
};

void PhoneBook::AddContact(void) {
	static int i;
	this->Contacts[i % 8].Add(i);
	std::cout << "Contact successfully added!" << std::endl;
    if (amount < 8)
        amount++;
	i++;
}

void PhoneBook::Search(void) {
    for (int i = 0; i < 8; i++) {
        this->Contacts[i].Display();
    }
    if (amount > 0) {
        std::cout << "Which contact would you like to view? (index)" << std::endl;
        std::cin.ignore();
        int input;
        bool valid = false;
        while (!valid) {
            std::cin >> input;
            if (input >= 0 && input <= 7 && input < amount)
                valid = true;
            else {
                std::cin.clear();
                std::cout << "Invalid index, Please try again" << std::endl;
            }
        }
        this->Contacts[input].View();
    }
}