/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:13:50 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/17 17:26:04 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::Start(void) {
    std::cout << "Available Commands" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "ADD: adds contact to the phonebook" << std::endl;
    std::cout << "SEARCH: displays a specific contact" << std::endl;
    std::cout << "EXIT: the program quits and the contacts are lost forever!" << std::endl;
};

void PhoneBook::AddContact(void) {
	static int i;
	this->Contacts[i % 8].Init(i);
	std::cout << "Contact successfully added!" << std::endl;
	i++;
}

void PhoneBook::Search(void) {
    
}