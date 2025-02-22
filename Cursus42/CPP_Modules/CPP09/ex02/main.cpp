/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:43:58 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/22 20:37:09 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> parseInput(char **argv) {
    std::vector<int> _vec;
    for (int i = 1; argv[i]; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!isdigit(argv[i][j]))
                throw std::runtime_error("Error: Invalid argument");
        }
        try {
        int _arg = atoi(argv[i]);
        if (_arg < 0)
            throw std::runtime_error("Error: Non positive int found");
        _vec.push_back(_arg);
        } catch(std::exception &) {
            throw std::runtime_error("Error: Invalid argument");
        }
    }
    return _vec;
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Error: Invalid argument count" << std::endl;
        return 1;
    }
    try {
    std::vector<int> _Input = parseInput(argv);
    PmergeMe sort(argc, _Input);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}