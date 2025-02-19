/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:28:29 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/19 17:32:36 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        return (std::cout << "Error: Invalid argument count." << std::endl ,1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
        return (std::cout << "Error: Unable to open file" << std::endl, 1);
    if (file.peek() == std::ifstream::traits_type::eof())
        return (std::cout << "Error: File is empty." << std::endl, 1);
    try {
        BitcoinExchange btc(file);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    file.close();
    return 0;
}