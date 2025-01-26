/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:16:36 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 11:34:25 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

int main() {
    //! TODO
    Data *ptr = new Data;
    uintptr_t raw;
    
    std::cout << ptr->getData() << std::endl;
    raw = Serializer::serialize(ptr);
    std::cout << raw << std::endl;
    ptr = Serializer::deserialize(raw);
    std::cout << ptr->getData() << std::endl;

    delete ptr;
    return 0;
}