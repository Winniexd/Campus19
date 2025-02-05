/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:28:29 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/05 12:16:59 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Invalid argument count" << std::endl;
        return 1;
    }
    std::ifstream file;
    std::string fileName = argv[1];
    file.open(fileName.c_str(), std::ios::in);
    if (!file) {
        std::cout << "Error: Unable to open file" << std::endl;
        return 2;
    }
    file.close();
    return 0;
}