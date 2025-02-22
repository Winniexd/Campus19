/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:43:54 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/22 21:08:58 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <exception>
#include <ctime>
#include <iomanip>
#include <typeinfo>

class PmergeMe {
    private:
        const int _Arg_count;
        std::vector<int> _Vector;
        std::deque<int> _Deque;
        PmergeMe();
    public:
        ~PmergeMe();
        PmergeMe(int argc, const std::vector<int> &input);

        template <typename Container>
        void printElements(Container &c) {
            for (typename Container::iterator it = c.begin(); it != c.end(); it++) {
                std::cout << *it << " ";
            }
        }

        template <typename Container>
        void sort(Container &c) {
            std::cout << "Before: ";
            printElements(c);
            std::cout << std::endl;
            clock_t start = clock();
            int _Size_half = c.size() / 2;

            Container left(c.begin(), c.begin() + _Size_half);
            Container right(c.begin() + _Size_half, c.end());
            Container res;
            std::sort(left.begin(), left.end());
            std::sort(right.begin(), right.end());
            while (!left.empty() && !right.empty()) {
                if (left.front() == right.front())
                    throw std::runtime_error("Error: Duplicate value found");
                if (left.front() < right.front()) {
                    res.push_back(left.front());
                    left.erase(left.begin());
                }
                else {
                    res.push_back(right.front());
                    right.erase(right.begin());
                }
            }
            res.insert(res.end(), left.begin(), left.end());
            res.insert(res.end(), right.begin(), right.end());
            
            clock_t end = clock();
            std::cout << "After: ";
            printElements(res);
            std::cout << std::endl;
            std::string type = (std::string(typeid(c).name()).find("vector") != std::string::npos ? "vector": "deque");
            std::cout << "Time to process a range of " << _Arg_count << " elements with std::" << type << " : ";
            std::cout << std::fixed << std::setprecision(5) << (double)(end - start) / CLOCKS_PER_SEC << "ms" << std::endl;
        }
};

#endif