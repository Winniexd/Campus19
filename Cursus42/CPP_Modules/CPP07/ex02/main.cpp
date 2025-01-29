/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:44:33 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/29 13:56:20 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> array1(3);
    
    Array<int> array3 = array1;
    
    for (unsigned int i = 0; i < array1.size(); i++) {
        std::cout << "array1[" << i << "]: " << array1[i] << std::endl;
    }
    std::cout << std::endl;
    for (unsigned int i = 0; i < array3.size(); i++) {
        std::cout << "array3[" << i << "]: " << array3[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Testing change of values and deep copy (changing array1[0] to 1)" << std::endl;
    array1[0] = 1;
    std::cout << "array1[0]: " << array1[0] << std::endl;
    std::cout << "array3[0]: " << array3[0] << std::endl;
    std::cout << std::endl;
    std::cout << "Testing OutOfBoundsException" << std::endl;
    try {
        std::cout << array1[3] << std::endl;
    } catch (std::exception &e) {
        std::cout << "array1[3]: " << e.what() << std::endl;
    }
}