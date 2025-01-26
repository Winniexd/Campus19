/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:16:27 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 11:21:37 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#pragma once
#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Data;

class Serializer {
    private:
        //static Data* deserialize(uintptr_t raw);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif