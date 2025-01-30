/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:03 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/30 20:46:04 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

class Span {
    private:
        unsigned int N;
        unsigned int size;
        std::vector<int> array;
        
    public:
        Span(unsigned int max);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& rhs);
    
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
    class inSufficientNumbersException: public std::exception {
        virtual const char* what() const throw();
    };
    class maxNumbersException: public std::exception {
        virtual const char* what() const throw();
    };
};

#endif