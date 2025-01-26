/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:22:40 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 11:25:20 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP
#pragma once
#include "serialization.hpp"

class Data {
    private:
        std::string data;
    public:
        Data();
        ~Data();
        Data(Data const &src);
        Data& operator=(Data const &rhs);
        std::string getData() const;
};

#endif