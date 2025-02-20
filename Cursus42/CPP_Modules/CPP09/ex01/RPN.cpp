/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:06:22 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/20 19:40:39 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(char token) {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int performOperation(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by 0");
            return b / a;
        default:
            throw std::runtime_error("Invalid operator");
    }
}


void RPN::calculate(std::string expression) {
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() != 1)
            throw std::runtime_error("Error");
        char c = token[0];
        if (isdigit(c))
            _Stack.push(c - '0');
        else if (isOperator(c) && _Stack.size() >= 2) {
            int a = _Stack.top();
            _Stack.pop();
            int b = _Stack.top();
            _Stack.pop();
            int res = performOperation(c, a, b);
            _Stack.push(res);
        }
        else
            throw std::runtime_error("Error: Invalid character");
    }
    if (_Stack.size() != 1)
        throw std::runtime_error("Error: Stack contains more than 1 element at the end");
    std::cout << _Stack.top() << std::endl;
}

RPN::RPN(std::string expression) {
    try {
        calculate(expression);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

RPN::RPN() {
    
}

RPN::~RPN() {

}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs) {
        this->_Stack = std::stack<int>(rhs._Stack);
    }
    return *this;
}

RPN::RPN(const RPN& src) {
    this->_Stack = std::stack<int>(src._Stack);
}