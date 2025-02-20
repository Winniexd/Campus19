/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:06:25 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/20 19:12:39 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
    private:
        std::stack<int> _Stack;
    public:
        RPN();
        RPN(std::string expression);
        ~RPN();
        RPN& operator=(const RPN& rhs);
        RPN(const RPN& src);
        void calculate(std::string expression);
};

#endif