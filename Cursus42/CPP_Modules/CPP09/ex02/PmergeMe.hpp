/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:43:54 by winniexd          #+#    #+#             */
/*   Updated: 2025/02/24 20:34:45 by winniexd         ###   ########.fr       */
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
        void merge(Container &c, int left, int mid, int right) {
            Container leftArr(c.begin() + left, c.begin() + mid + 1);
            Container rightArr(c.begin() + mid + 1, c.begin() + right + 1);
        
            long unsigned int i = 0, j = 0, k = left;
        
            while (i < leftArr.size() && j < rightArr.size()) {
                if (leftArr[i] <= rightArr[j]) {
                    c[k] = leftArr[i];
                    i++;
                } else {
                    c[k] = rightArr[j];
                    j++;
                }
                k++;
            }
            while (i < leftArr.size()) {
                c[k] = leftArr[i];
                i++;
                k++;
            }
            while (j < rightArr.size()) {
                c[k] = rightArr[j];
                j++;
                k++;
            }
        }
        

        template <typename Container>
        void mergeSort(Container &c, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;

                mergeSort(c, left, mid);
                mergeSort(c, mid + 1, right);

                merge(c, left, mid, right);
            }
        }

        template <typename Container>
        void sort(Container &c) {
            std::cout << "Before: ";
            printElements(c);
            std::cout << std::endl;
            clock_t start = clock();
            
            mergeSort(c, 0, c.size() - 1);
            
            clock_t end = clock();
            std::cout << "After: ";
            printElements(c);
            std::cout << std::endl;
            std::string type = (std::string(typeid(c).name()).find("vector") != std::string::npos ? "vector": "deque");
            std::cout << "Time to process a range of " << _Arg_count << " elements with std::" << type << " : ";
            std::cout << std::fixed << std::setprecision(5) << (double)(end - start) / CLOCKS_PER_SEC << "ms" << std::endl;
        }
};

#endif