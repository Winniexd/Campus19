/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:57:25 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/21 13:15:34 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b = Bureaucrat("Apple", 11);
    Bureaucrat c = Bureaucrat();
    Form f = Form("myForm", false, 10);
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << f << std::endl;
    b.signForm(f);
    return 0;
}