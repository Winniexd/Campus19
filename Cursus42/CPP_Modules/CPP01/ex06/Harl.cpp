/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:42:28 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 17:52:47 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	func funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string funcnames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && funcnames[i].compare(level))
		i++;
	switch(i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}


void Harl::debug(void) {
	std::cout << "debug level" << std::endl;
}

void Harl::info(void) {
	std::cout << "info level" << std::endl;
}

void Harl::warning(void) {
	std::cout << "warning level" << std::endl;
}

void Harl::error(void) {
	std::cout << "error level" << std::endl;	
}

