/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:53 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/30 20:46:44 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int max): N(max) {
    this->size = 0;
}

Span::~Span() {
    
}

Span::Span(const Span& src) {
    this->N = src.N;
    this->size = src.size;
}

Span& Span::operator=(const Span& rhs) {
    this->N = rhs.N;
    this->size = rhs.size;

    return *this;
}

void Span::addNumber(int n) {
    if (size == N)
        throw maxNumbersException();
    this->array.push_back(n);
    this->size++;
}

int Span::shortestSpan() const {
    if (size < 2)
        throw inSufficientNumbersException();
    std::vector<int> tmp = array;
    std::sort(tmp.begin(), tmp.end());
    int min = INT_MAX;
    
    for (std::vector<int>::iterator it_begin = tmp.begin(); it_begin != tmp.end() - 1; ++it_begin) {
        int diff = *(it_begin + 1) - *it_begin;
        if (diff < min)
            min = diff;
    }
    
    return (min);
}

int Span::longestSpan() const {
    if (size < 2)
        throw inSufficientNumbersException();
    std::vector<int> tmp = array;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[size - 1] - tmp[0]);
}

const char* Span::inSufficientNumbersException::what() const throw() {
    return "InSufficient Number in vector for Span";
}

const char* Span::maxNumbersException::what() const throw() {
    return "Span has already reached the maximum element amount";
}