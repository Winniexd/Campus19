/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:28:45 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/20 18:30:56 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <exception>

class BitcoinExchange {
    private:
        std::map<std::string, float> keypair;
    public:
        void parseDataBase();
        void parseInput(std::ifstream &file);
        void findValue(std::string date, float value);
        
        BitcoinExchange();
        BitcoinExchange(std::ifstream &file);
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange& rhs);
        BitcoinExchange(BitcoinExchange& src);
    
    class MissingDataBase: public std::exception {
        virtual const char* what() const throw();
    };
    class InvalidData: public std::exception {
        virtual const char* what() const throw();
    };
};

#endif