/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abomination.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:02:31 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/01 12:09:36 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abomination.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {

}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
    
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& src) {
    *this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& rhs) {
    if (this != &rhs) {
        std::stack<T, Container>::operator=(rhs);
    }
    return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return this->c.end();
}
