/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:27 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/30 20:48:15 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(4);
    }   catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Span test = Span(1);
    test.addNumber(1);
    try {
        test.longestSpan();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}