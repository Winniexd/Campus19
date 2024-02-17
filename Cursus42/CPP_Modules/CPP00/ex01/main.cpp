/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:17:32 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/17 15:43:58 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void) {
    PhoneBook p;
    std::string input = "";
    p.Start();
    while (input.compare("EXIT")) {
        if (!input.compare("ADD"))
            p.AddContact();
        else if (!input.compare("SEARCH")) {
			p.Start();
		}
		std::cin >> input;
    }
    return (0);
}