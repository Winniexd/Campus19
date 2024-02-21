/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:42:28 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/20 13:29:10 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	func funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string funcnames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (!funcnames[i].compare(level))
			(this->*funcs[i])();
			
}

void Harl::debug(void) {
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-" << std::endl;
	std::cout << "ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "cannot believe adding extra bacon costs more money. You didn't put" << std::endl;
	std::cout << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for" << std::endl;
	std::cout << "years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}