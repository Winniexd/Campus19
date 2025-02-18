/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:30:32 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/18 19:18:28 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::parseDataBase() {
    std::ifstream db("data.csv");
    std::string line;

    if (!db.is_open())
        throw MissingDataBase();
    
    while (std::getline(db, line)) {
        if (line == "date,exchange_rate")
            continue;
        
        std::string date = line.substr(0, line.find(','));
        float value = std::atof((line.substr(line.find(',') + 1)).c_str());
        
        this->keypair.insert(std::make_pair(date, value));
    }
    if (this->keypair.empty())
        throw InvalidData();
}

void BitcoinExchange::parseInput(std::ifstream &file) {
    (void)file;
}

BitcoinExchange::BitcoinExchange(std::ifstream &file) {
    parseDataBase();
    for (std::map<std::string, float>::iterator it = this->keypair.begin(); it != this->keypair.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    (void)file;
    //parseInput(file);
}

const char* BitcoinExchange::MissingDataBase::what() const throw() {
    return "Unable to open DataBase";
}

const char* BitcoinExchange::InvalidData::what() const throw() {
    return "No valid data found";
}