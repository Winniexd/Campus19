/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:32:13 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 11:29:55 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

Data::Data(): data("Some random value") {
    std::cout << "Default data constructor called" << std::endl;
}

Data::~Data() {
    std::cout << "Default data destructor called" << std::endl;
}

Data& Data::operator=(Data const &rhs) {
    if (this != &rhs)
        this->data = rhs.data;
    return *this;
}

Data::Data(Data const &src) {
    *this = src;
}

std::string Data::getData() const {
    return this->data;
}
