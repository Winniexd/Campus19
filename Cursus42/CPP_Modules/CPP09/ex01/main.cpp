/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:06:19 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/20 18:54:36 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Invalid amount of arguments" << std::endl;
        return 1;
    }
    std::string expression(argv[1]);
    RPN rpn(expression);
    return 0;
}