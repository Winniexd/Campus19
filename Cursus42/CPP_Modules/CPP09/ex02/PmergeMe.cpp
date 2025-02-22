/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:43:47 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/22 20:04:04 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, const std::vector<int> &_Input): _Arg_count(argc - 1), _Vector(_Input), _Deque(_Input.begin(), _Input.end()) {
    sort(_Vector);
    sort(_Deque);
}

PmergeMe::~PmergeMe() {
    
}