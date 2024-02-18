/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:52:29 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/18 14:00:50 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN.";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "str Address: " << &str << std::endl;
    std::cout << "stringPTR Address: " << stringPTR << std::endl;
    std::cout << "stringREF Address: " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "str Value: " << str << std::endl;
    std::cout << "stringPTR Value: " << *stringPTR << std::endl;
    std::cout << "stringREF Value: " << stringREF << std::endl;

    return (0);
}