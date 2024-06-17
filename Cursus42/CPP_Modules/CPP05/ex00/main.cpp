/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:25 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/16 13:36:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b = Bureaucrat("Apple", 150);
    Bureaucrat c = Bureaucrat();
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    try {
        b.decrementGrade();
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}