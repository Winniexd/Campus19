/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abomination.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:53:03 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/01 12:11:31 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABOMINATION_HPP
#define ABOMINATION_HPP
#pragma once
#include <iostream>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& src);
        MutantStack& operator=(const MutantStack& rhs);

        typedef typename Container::iterator iterator;
        iterator begin();
        iterator end();
};

#include "abomination.tpp"

#endif