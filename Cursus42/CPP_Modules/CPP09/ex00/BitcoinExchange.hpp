/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:28:45 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/05 12:19:41 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <exception>

class btc {
    private:
        std::map<std::string, float> keypair;
    public:
        template <typename T>
        void parse();
    
        btc(const char *file);
    class MissingDataBase: public std::exception {
        virtual const char* what() const throw();
    };
};

#endif