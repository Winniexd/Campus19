/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:29:07 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 20:47:23 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printVal(int &val) {
    std::cout << val << std::endl;
}

int main() {
    int arr[] = {1, 2, 3};

    ::iter(arr, 3, &printVal);
    std::cout << std::endl;
    ::iter(arr, 3, &printValTemplate);
}