/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:30:32 by mdreesen          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:08 by winniexd         ###   ########.fr       */
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
    db.close();
}

bool checkValue(float value) {
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool checkDate(int year, int month, int day) {
    if (year <= 0 || month <= 0 || day <= 0)
        return false;

    if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        return false;
    
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return day <= 31;
        case 4: case 6: case 9: case 11:
            return day <= 30;
        case 2:
            return day <= (isLeap ? 29 : 28);
        default:
            return false;
    }
}

void BitcoinExchange::findValue(std::string date, float value) {
    std::map<std::string, float>::iterator it = this->keypair.find(date);
    if (it != this->keypair.end()) {
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        return ;
    }

    it = this->keypair.upper_bound(date);
    if (it != this->keypair.begin()) {
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        return ;
    }
    std::cout << "Couldn't find the correct key." << std::endl;
}

void BitcoinExchange::parseInput(std::ifstream &file) {
    std::string line;
    std::string date;
    int year, month, day;
    float value;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        date = line.substr(0, line.find('|') - 1);
        char delimiter;
        ss >> year >> delimiter >> month >> delimiter >> day >> delimiter >> value;
        if (!checkDate(year, month, day)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!checkValue(value))
            continue;
        findValue(date, value);
    }
}

void printData(std::map<std::string, float> keypair) {
    for (std::map<std::string, float>::iterator it = keypair.begin(); it != keypair.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

BitcoinExchange::BitcoinExchange() {
    
}

BitcoinExchange::~BitcoinExchange() {
    
}

BitcoinExchange::BitcoinExchange(std::ifstream &file) {
    parseDataBase();
    //printData(this->keypair);
    parseInput(file);
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& src) {
    *this = src;
}

const char* BitcoinExchange::MissingDataBase::what() const throw() {
    return "Error: Unable to open DataBase";
}

const char* BitcoinExchange::InvalidData::what() const throw() {
    return "Error: Contains invalid data";
}