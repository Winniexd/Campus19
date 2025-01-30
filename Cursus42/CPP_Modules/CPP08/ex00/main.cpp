/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:07:57 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/30 16:01:26 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find.hpp"
#include <list>
#include <vector>

int main() {
    std::list<int> list;
    std::vector<int> vector;
    
    for (unsigned int i = 0; i < 11; i++) {
        list.push_back(i);
        vector.push_back(i);
    }

    for (std::list<int>::iterator i = list.begin(); i != list.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
    std::list<int>::iterator it_list = ::easyfind(list, 3);
    if (it_list != list.end())
        std::cout << "Value found: " << *it_list << std::endl;
    std::vector<int>::iterator it_vec = ::easyfind(vector, 5);
    if (it_vec != vector.end())
        std::cout << "Value found: " << *it_vec << std::endl;
}