/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:04:45 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/20 15:18:09 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void mysed(std::fstream *file, std::string s1, std::string s2) {
	
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Usage: ./mysed <infile> <s1> <s2>" << std::endl;
        return (1);
    }
    std::fstream file;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
    file.open(argv[1], std::ios::in);
    if (!file) {
        std::cout << "Unable to open file" << std::endl;
        return (2);
    }
    mysed(&file, s1, s2);
    file.close();
    return (0);
}
